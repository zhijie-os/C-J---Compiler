#include "codeGen.h"
#include "semantic.h"

#define ASM(x) std::cout << x << std::endl;
#define ASM1(x) std::cout << "   " << x << std::endl;
#define ASM2(x) std::cout << "       " << x << std::endl;
#define EMPTY_LINE std::cout << std::endl;

#define DATA_SIZE 4

const std::unordered_map<std::string, std::string> BinaryInstruction{
    {"==", "seq"}, {"!=", "sne"}, {">", "sgt"}, {">=", "sge"}, {"<", "slt"}, {"<=", "sle"}, {"+", "addu"}, {"-", "subu"}, {"*", "mul"}, {"/", "div"}, {"%", "rem"}};

std::unordered_map<std::string, std::string> VarLabel;
std::unordered_map<std::string, std::string> FuncLabel =
    {
        {"printi", "printi"}, {"printc", "printc"}, {"printb", "printb"}, {"prints", "prints"}};

// const std::unordered_map<std::string, std::string> UnaryInstruction
// {
//     {"x","!"}, {"negu","-"};
// };

int label_count = 0;

void yycodegen(AST *root)
{
    GenPreclude();

    for (auto c : root->children)
    {
        GenCode(c);
    }
}

void GenGlobalVar(AST *root)
{
    for (auto c : root->children)
    {
        if (c->type == NodeType::GLOBAL_VAR_DEC)
        {
            std::string label = GenLabel();
            VarLabel.insert({ChildLiteral(c, 1), label});
            ASM("    .data");
            ASM("    .align 2");
            ASM(label + ":    .space 4");
            EMPTY_LINE;
        }
    }
}

void GenID(AST *root)
{
    if (root->type == NodeType::IDENTIFIER)
    {
        ASM1("# Grab ID")
        if (root->f_record)
        {
            ASM1("la     $a0, " + FuncLabel.find(root->attribute->literal)->second);
        }
        else
        {
            if (root->id_record->global)
            {
                ASM1("la    $a0, " + VarLabel.find(root->attribute->literal)->second);
            }
            else
            {
                ASM1("lw    $a0, " + std::to_string(4 + 4 * root->id_record->global) + "($fp)");
            }
        }
    }
}

void GenMain(AST *root)
{
    if (root->type == NodeType::MAIN_DEC)
    {
        ASM1(".text");
        ASM1(".globl main");
        ASM("main:");

        int num_local = SYMBOL_TABLE.find(ChildLiteral(root, 1))->second.size();

        /**
         *                 <- SP
         *  local variables
         *  previous FP pointed address
         *  return address
         *  params
         *         <- FP
         */

        ASM1("# function setup")
        // store old FP
        ASM1("move  $fp, $sp");

        // generate code for the function block
        GenCode(Child(root, 3));

        // load back the return address
        ASM1("lw    $ra, 4($sp)");
        // shrink the stack
        ASM1("addu  $sp, $sp, " + std::to_string(num_local * 4 + 4));

        ASM1("li    $v0,10");
        ASM1("syscall");
    }
}

/**
 * Assumption: the parameters are already pushed onto the stack,
 * $a0 = the number of parameter on the stack
 */
void GenFunc(AST *root)
{
    if (root->type == NodeType::FUNC_DEC)
    {

        // figure out the number of parameters and number of local variables
        int num_params = GLOBAL_FUNC.find(ChildLiteral(root, 1))->second.paramType.size();
        int num_local = SYMBOL_TABLE.find(ChildLiteral(root, 1))->second.size() - num_params;

        ASM1(".text")

        std::string l = GenLabel();
        FuncLabel.insert({ChildLiteral(root, 1), l}); // to look up

        ASM(l);
        /**
         *                 <- SP
         *  local variables
         *  previous FP pointed address
         *  return address
         *  params
         *         <- FP
         */

        ASM1("# function setup")
        // store old FP
        ASM1("move  $fp, $sp");
        ASM1("sw    $ra, 0($sp)");
        ASM1("subu  $sp, $sp,-4");

        // generate code for the function block
        GenCode(Child(root, 3));

        // load back the return address
        ASM1("lw    $ra, 4($sp)");
        // shrink the stack
        ASM1("subu  $sp, $sp, " + std::to_string(num_params * 4 + 8));
        // load back the old function pointer
        ASM1("lw    $fp, 0($sp)");
        // jump return
        ASM1("jr    $ra");
    }
}

/**
 *
 */
void GenFuncCall(AST *root)
{
    if (root->type == NodeType::FUNC_CALL)
    {
        ASM1("# Function Call Setup")
        ASM1("sw    $fp, 0($sp)"); // store FP
        ASM1("subu  $sp, $sp, 4"); // expand the stack

        // for every actual, push on the stack but backwards
        for (int i = Child(root, 1)->children.size() - 1; i >= 0; i--)
        {
            ASM1("# Create Actuals")
            GenCode(Child(root, 1)->children[i]);
            ASM1("sw    $a0, 0($sp)");
            ASM1("subu  $sp, $sp, 4");
        }

        // look up the function label
        std::string function_label = FuncLabel.find(ChildLiteral(root, 0))->second;
        // jump and link
        ASM1("jal   " + function_label);
    }
}

// Put a number on the top of the stack
void GenNumber(AST *root)
{
    if (root->type == NodeType::NUMBER)
    {
        ASM1("# Generate Number")
        ASM1("li    $a0," + root->attribute->literal); // load the literal
    }
}

// Put a bool on the top of the stack
void GenBoolean(AST *root)
{
    if (root->type == NodeType::TRUE)
    {
        ASM1("li    $a0, TRUE"); // true
    }
    if (root->type == NodeType::FALSE)
    {
        ASM1("li    $a0, FALSE"); // false
    }
}

void GenString(AST *root)
{
    if (root->type == NodeType::STRING)
    {

        std::string str_label = GenLabel();
        // create new string data
        ASM1("  .data");
        ASM1("str_" + str_label + ": .asciiz \"" + root->attribute->literal + "\"");

        // back to text
        ASM1("  .text");

        // load onto the top of the stack
        ASM1("la    $a0, str_" + str_label);
    }
}

void GenCondition(AST *root)
{
    if (root->type == NodeType::IF_ELSE)
    {
        GenExpr(Child(root, 0));
        std::string true_label = GenLabel();
        std::string false_label = GenLabel();
        std::string end_label = GenLabel();

        // branch check
        ASM1("beq   $a0, TRUE, " + true_label);

        // if failed, goes in to false_label
        ASM(false_label);
        // gen code for the code inside the label;
        GenCode(Child(root, 2));
        // skip true label
        ASM1("b     " + end_label);

        // true label
        ASM(true_label);
        GenCode(Child(root, 1));

        // just keep it empty
        ASM(end_label);
    }

    if (root->type == NodeType::IF)
    {
        GenExpr(Child(root, 0));
        std::string end_label = GenLabel();
        // branch check
        ASM1("beq   $a0, FALSE, " + end_label);
        // otherwise, true, do this
        GenCode(Child(root, 1));
        // just keep it empty
        ASM(end_label);
    }
}

// the result would be register $a0
void GenExpr(AST *root)
{
    if (root->type == NodeType::BIN_ARITHMETIC || root->type == NodeType::BIN_LOGIC || root->type == NodeType::BIN_RELATION || root->type == NodeType::EQUIVALENCE)
    {

        GenCode(Child(root, 0)); // get lhs
        ASM1("sw    $a0, 0($sp)");
        ASM1("subu  $sp, $sp, 4"); // tempory store on the stack
        GenExpr(Child(root, 1));   // get rhs

        ASM1("lw    $t0, 4($sp)"); // rhs on the temp 1
        ASM1("addu  $sp, $sp, 4")  // restore the stack

        // store result on the $a0
        ASM1(BinaryInstruction.find(root->symbol)->second + "    $a0, $t0,$a0 "); // the result is on the temp 0
    }

    if (root->type == NodeType::ASSIGN)
    {

        ASM1("# ASSIGNMENT")
        GenCode(Child(root, 1));                                                                             // get rhs
        ASM1("sw    $a0, " + std::to_string(4 + 4 * root->children[0]->id_record->stackPosition) + "($fp)"); // lhs on the temp 1
    }

    if (root->type == NodeType::UN_ARITHMETIC)
    {
        GenExpr(Child(root, 0));
        ASM1("negu  $a0, $a0");
    }

    if (root->type == NodeType::UN_LOGIC)
    {
        GenExpr(Child(root, 0));
        ASM1("xori  $a0, $a0,1");
    }
}

std::string GenLabel()
{
    label_count++;
    return "L_" + std::to_string(label_count - 1) + ": ";
}

void GenCode(AST *root)
{
    GenNumber(root);
    GenString(root);
    GenBoolean(root);
    GenCondition(root);
    GenFunc(root);
    GenFuncCall(root);
    GenGlobalVar(root);
    GenExpr(root);
    GenMain(root);
    GenID(root);
    Descend(root);
}

void Descend(AST *root)
{
    if (root->type == NodeType::BLOCK || root->type == NodeType::STMT_EXPR)
    {
        for (auto c : root->children)
        {
            GenCode(c);
        }
    }
}

void GenPreclude()
{
    // halt
    // halt the program
    ASM1(".text");
    ASM("halt:");
    ASM1("li    $v0, 10"); // load instruction 10
    ASM1("syscall");       // exit via syscall

    // print int
    ASM1(".text");
    ASM("printi:");
    ASM1("move  $fp, $sp");
    ASM1("sw    $ra, 0($sp)");
    ASM1("subu  $sp, $sp,4");

    ASM1("lw    $a0, 4($fp)");
    ASM1("li    $v0, 1");
    ASM1("syscall");

    // load back the return address
    ASM1("lw    $ra, 4($sp)");
    // shrink the stack
    ASM1("subu  $sp, $sp, 12");
    // load back the old function pointer
    ASM1("lw    $fp, 0($sp)");
    // jump return
    ASM1("jr    $ra");

    EMPTY_LINE;
    EMPTY_LINE;

    // print string
    ASM("prints:");
    ASM1("move  $fp, $sp");
    ASM1("sw    $ra, 0($sp)");
    ASM1("subu  $sp, $sp,4");

    ASM1("lw    $a0, 8($fp)");
    ASM1("li    $v0, 4");
    ASM1("syscall");

    // load back the return address
    ASM1("lw    $ra, 4($sp)");
    // shrink the stack
    ASM1("subu  $sp, $sp, 12");
    // load back the old function pointer
    ASM1("lw    $fp, 0($sp)");
    // jump return
    ASM1("jr    $ra");

    // print char
    ASM("printc:");
    ASM1("move  $fp, $sp");
    ASM1("sw    $ra, 0($sp)");
    ASM1("subu  $sp, $sp,4");

    ASM1("lw    $a0, 8($fp)");
    ASM1("li    $v0, 11");
    ASM1("syscall");

    // load back the return address
    ASM1("lw    $ra, 4($sp)");
    // shrink the stack
    ASM1("subu  $sp, $sp, 12");
    // load back the old function pointer
    ASM1("lw    $fp, 0($sp)");
    // jump return
    ASM1("jr    $ra");
}

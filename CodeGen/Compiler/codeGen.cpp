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
        {"printi", "printi"}, {"printc", "printc"}, {"printb", "printb"}, {"prints", "prints"}, {"getchar", "getchar"}, {"halt", "halt"}};

int label_count = 0;

/**
 * Generate from 'PROGRAM' to leaves
 *
 */
void yycodegen(AST *root)
{
    GenPreclude();
    GenLabels(root);
    for (auto c : root->children)
    {
        GenCode(c);
    }
}

void GenLabels(AST *root)
{
    for (auto c : root->children)
    {
        if (c->type == NodeType::FUNC_DEC)
        {
            std::string l = GenLabel();
            FuncLabel.insert({ChildLiteral(c, 1), l}); // to look up
        }
        if (c->type == NodeType::GLOBAL_VAR_DEC)
        {
            std::string l = GenLabel();
            VarLabel.insert({ChildLiteral(c, 1), l}); // to look up
        }
    }
}
/**
 * @brief Generate Global Variable within '.data'
 *
 * @param root
 */
void GenGlobalVar(AST *root)
{
    if (root->type == NodeType::GLOBAL_VAR_DEC)
    {
        std::string label = VarLabel.find(ChildLiteral(root, 1))->second;
        ASM("    .data");
        ASM("    .align 2");
        ASM(label + ":    .space 4");
        EMPTY_LINE;
    }
}

/**
 * @brief Look up the rvalue of the identifier, put into $a0
 *
 * @param root
 */
void GenID(AST *root)
{
    if (root->type == NodeType::IDENTIFIER)
    {
        ASM1("# Grab ID")
        if (root->f_record)
        {
            // ASM1("la     $a0, " + FuncLabel.find(root->attribute->literal)->second);
            ASM1("# You do not need the ID for function");
        }
        else
        {
            if (root->id_record->global)
            {
                ASM1("la    $t0, " + VarLabel.find(root->attribute->literal)->second)
                ASM1("lw    $a0, 0($t0)");
            }
            else
            {
                ASM1("lw    $a0, " + std::to_string(4 + 4 * root->id_record->stackPosition) + "($fp)");
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
        ASM1("addiu  $sp, $sp, " + std::to_string(num_local * 4 + 4));

        ASM1("li    $v0,10");
        ASM1("syscall");

        EMPTY_LINE;
        EMPTY_LINE;
    }
}

/**
 * Assumption: the parameters are already pushed onto the stack,
 * $a0 = the number of parameter on the stack
 */
void GenFuncDec(AST *root)
{
    if (root->type == NodeType::FUNC_DEC)
    {

        // figure out the number of parameters and number of local variables
        int num_params = GLOBAL_FUNC.find(ChildLiteral(root, 1))->second.paramType.size();
        int num_local = SYMBOL_TABLE.find(ChildLiteral(root, 1))->second.size() - num_params;

        ASM1("# Begin of Function Declaration");
        ASM1(".text")

        std::string label = FuncLabel.find(ChildLiteral(root, 1))->second;
        ASM(label + ":");
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
        ASM1("subu  $sp, $sp,4");

        // generate code for the function block
        GenCode(Child(root, 3));

        // load back the return address
        ASM1("lw    $ra, 4($sp)");
        // shrink the stack
        ASM1("addiu  $sp, $sp, " + std::to_string((num_params + num_local) * 4 + 8));
        // load back the old function pointer
        ASM1("lw    $fp, 0($sp)");
        // jump return
        ASM1("jr    $ra");

        ASM1("# End of Function Declaration");
        EMPTY_LINE;
        EMPTY_LINE;
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

        if (SYMBOL_TABLE.find(ChildLiteral(root, 0)) != SYMBOL_TABLE.end())
        {
            int num_local = SYMBOL_TABLE.find(ChildLiteral(root, 0))->second.size() -
                            GLOBAL_FUNC.find(ChildLiteral(root, 0))->second.paramType.size();

            ASM1("# Create space for local variables")
            for (int i = 0; i < num_local; i++)
            {
                ASM1("subu  $sp, $sp, 4");
            }
        }

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
        ASM1("li    $a0, " + root->attribute->literal); // load the literal
    }
}

// Put a bool on the top of the stack
void GenBoolean(AST *root)
{
    if (root->type == NodeType::TRUE)
    {
        ASM1("li    $a0, 1"); // true
    }
    if (root->type == NodeType::FALSE)
    {
        ASM1("li    $a0, 0"); // false
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
        GenCode(Child(root, 0));
        std::string true_label = GenLabel();
        std::string false_label = GenLabel();
        std::string end_label = GenLabel();

        // branch check
        ASM1("beq   $a0, 1, " + true_label);

        // if failed, goes in to false_label
        ASM(false_label + ":");
        // gen code for the code inside the label;
        GenCode(Child(root, 2));
        // skip true label
        ASM1("b     " + end_label);

        // true label
        ASM(true_label + ":");
        GenCode(Child(root, 1));

        // just keep it empty
        ASM(end_label + ":");
    }

    if (root->type == NodeType::IF)
    {
        GenCode(Child(root, 0));
        std::string end_label = GenLabel();
        // branch check
        ASM1("beq   $a0, 0, " + end_label);
        // otherwise, true, do this
        GenCode(Child(root, 1));
        // just keep it empty
        ASM(end_label + ":");
    }
}

void GenBreak(AST *root)
{
    if (root->type == NodeType::BREAK)
    {
        while (root->type!=NodeType::WHILE)
        {
            root = root->parent;
        }

        ASM1("b     "+root->break_label);
    }
}

void GenWhile(AST *root)
{
    if (root->type == NodeType::WHILE)
    {

        std::string test_label = GenLabel();
        std::string body_label = GenLabel();
        std::string end_label = GenLabel();

        root->break_label = end_label;

        ASM1("# WHILE TEST");
        ASM(test_label + ":");
        GenCode(Child(root, 0));

        ASM1("# WHILE BODY");
        // branch check
        ASM1("beq   $a0, 0, " + end_label);

        // if failed, goes in to false_label
        ASM(body_label + ":");
        // gen code for the code inside the label;
        GenCode(Child(root, 1));
        // skip true label
        ASM1("b     " + test_label);
        // just keep it empty
        ASM1("# WHILE END");
        ASM(end_label + ":");
    }
}

// the result would be register $a0
void GenExpr(AST *root)
{
    if (root->type == NodeType::BIN_ARITHMETIC || root->type == NodeType::BIN_RELATION || root->type == NodeType::EQUIVALENCE)
    {

        GenCode(Child(root, 0)); // get lhs
        ASM1("sw    $a0, 0($sp)");
        ASM1("subu  $sp, $sp, 4"); // tempory store on the stack
        GenCode(Child(root, 1));   // get rhs

        ASM1("lw    $t0, 4($sp)"); // lhs on the temp 1
        ASM1("addiu  $sp, $sp, 4")  // restore the stack

        // store result on the $a0
        ASM1(BinaryInstruction.find(root->symbol)->second + "    $a0, $t0,$a0 "); // the result is on the temp 0
    }

    if (root->type == NodeType::BIN_LOGIC)
    {
    }

    if (root->type == NodeType::ASSIGN)
    {
        ASM1("# ASSIGNMENT")
        // generate value of the RHS
        GenCode(Child(root, 1));
        if (Child(root, 0)->id_record->global)
        {
            // global variable
            std::string label = VarLabel.find(ChildLiteral(root, 0))->second;
            ASM1("la    $t0, " + label); // load the address of the variable
            ASM1("sw    $a0, 0($t0)");   // store the value into the address
        }
        else
        {
            // local variable, generate value, assign = store in the stack
            ASM1("sw    $a0, " + std::to_string(4 + 4 * root->children[0]->id_record->stackPosition) + "($fp)");
        }
    }

    if (root->type == NodeType::UN_ARITHMETIC)
    {
        GenCode(Child(root, 0));
        ASM1("negu  $a0, $a0");
    }

    if (root->type == NodeType::UN_LOGIC)
    {
        GenCode(Child(root, 0));
        ASM1("xori  $a0, $a0,1");
    }

    if (root->type == NodeType::RETURN)
    {
        if (!root->children.empty())
        {
            GenCode(root->children[0]);
        }

        // load back the return address
        ASM1("lw    $ra, 4($sp)");
        // shrink the stack
        ASM1("addiu  $sp, $sp, " + std::to_string(numParam(root) * 4 + 8));
        // load back the old function pointer
        ASM1("lw    $fp, 0($sp)");
        // jump return
        ASM1("jr    $ra");
    }
}

int numParam(AST *root)
{
    while (root->type != NodeType::FUNC_DEC)
    {
        root = root->parent;
    }
    return GLOBAL_FUNC.find(ChildLiteral(root, 1))->second.paramType.size();
}
/**
 * @brief Generate a new label and return
 *
 * @return std::string, the new label
 */
std::string GenLabel()
{
    label_count++;
    return "L_" + std::to_string(label_count - 1);
}

void GenCode(AST *root)
{

    GenMain(root);
    GenNumber(root);
    GenString(root);
    GenBoolean(root);
    GenCondition(root);
    GenFuncDec(root);
    GenFuncCall(root);
    GenBreak(root);
    GenWhile(root);
    GenGlobalVar(root);
    GenExpr(root);
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

/**
 * @brief Define function Library
 *
 */
void GenPreclude()
{
    ASM1("# Start of the predefined functions")
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
    ASM1("addiu  $sp, $sp, 12");
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

    ASM1("lw    $a0, 4($fp)");
    ASM1("li    $v0, 4");
    ASM1("syscall");

    // load back the return address
    ASM1("lw    $ra, 4($sp)");
    // shrink the stack
    ASM1("addiu  $sp, $sp, 12");
    // load back the old function pointer
    ASM1("lw    $fp, 0($sp)");
    // jump return
    ASM1("jr    $ra");

    EMPTY_LINE;
    EMPTY_LINE;

    // print char
    ASM("printc:");
    ASM1("move  $fp, $sp");
    ASM1("sw    $ra, 0($sp)");
    ASM1("subu  $sp, $sp,4");

    ASM1("lw    $a0, 4($fp)");
    // ASM1("subu  $a0, 32");
    ASM1("li    $v0, 11");
    ASM1("syscall");

    // load back the return address
    ASM1("lw    $ra, 4($sp)");
    // shrink the stack
    ASM1("addiu  $sp, $sp, 12");
    // load back the old function pointer
    ASM1("lw    $fp, 0($sp)");
    // jump return
    ASM1("jr    $ra");

    EMPTY_LINE;
    EMPTY_LINE;

    // printb
    ASM("printb:");
    ASM1("move  $fp, $sp");
    ASM1("sw    $ra, 0($sp)");
    ASM1("subu  $sp, $sp,4");

    ASM1("lw    $a0, 4($fp)");
    ASM1("li    $v0, 1");
    ASM1("syscall");

    // load back the return address
    ASM1("lw    $ra, 4($sp)");
    // shrink the stack
    ASM1("addiu  $sp, $sp, 12");
    // load back the old function pointer
    ASM1("lw    $fp, 0($sp)");
    // jump return
    ASM1("jr    $ra");

    EMPTY_LINE;
    EMPTY_LINE;
    // getchar
    ASM("getchar:");
    ASM1("move  $fp, $sp");
    ASM1("sw    $ra, 0($sp)");
    ASM1("subu  $sp, $sp,4");

    // read char
    ASM1("li    $v0, 12");
    ASM1("syscall");
    // move to $a0
    ASM1("addiu  $a0, $v0, 0");

    // load back the return address
    ASM1("lw    $ra, 4($sp)");
    // shrink the stack
    ASM1("addiu  $sp, $sp, 8");
    // load back the old function pointer
    ASM1("lw    $fp, 0($sp)");
    // jump return
    ASM1("jr    $ra");

    ASM1("# End of predefined functions")

    EMPTY_LINE;
    EMPTY_LINE;
}

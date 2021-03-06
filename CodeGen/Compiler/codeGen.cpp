#include "codeGen.h"
#include "semantic.h"

/**
 *  predefined macros
 */

#define ASM(x) std::cout << x << std::endl;               // print a line with no indentation
#define ASM1(x) std::cout << "   " << x << std::endl;     // print a line with a tab preceding
#define ASM2(x) std::cout << "       " << x << std::endl; // print a line with two tabs preceding
#define EMPTY_LINE std::cout << std::endl;                // print an empty line

// operator lookup table
const std::unordered_map<std::string, std::string> BinaryInstruction{
    {"==", "seq"}, {"!=", "sne"}, {">", "sgt"}, {">=", "sge"}, {"<", "slt"}, {"<=", "sle"}, {"+", "addu"}, {"-", "subu"}, {"*", "mul"}, {"/", "div"}, {"%", "rem"}, {"&&", "and"}, {"||", "or"}};

// variable label lookup table
std::unordered_map<std::string, std::string> VarLabel;

// function label loopup table
std::unordered_map<std::string, std::string> FuncLabel =
    {
        {"printi", "printi"}, {"printc", "printc"}, {"printb", "printb"}, {"prints", "prints"}, {"getchar", "getchar"}, {"halt", "halt"}};

// label counter: auto increament when assign a new label
int label_count = 0;

/**
 * Generate from 'PROGRAM' to leaves
 */
void yycodegen(AST *root)
{
    GenPreclude();   // generate code for predefined funcitons
    GenLabels(root); // generate labels for the global declared functions and variables

    for (auto c : root->children) // traverse the tree
    {
        GenCode(c);
    }
}

/**
 *  Generate labels for the global declared functions and variables
 */
void GenLabels(AST *root)
{
    for (auto c : root->children)
    {
        if (c->type == NodeType::FUNC_DEC)
        {
            // if it is a global function, insert the label in the look up table
            std::string l = GenLabel();
            FuncLabel.insert({ChildLiteral(c, 1), l}); // to look up
        }
        if (c->type == NodeType::GLOBAL_VAR_DEC)
        {
            // if it is a global variable, insert the label in the look up table
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
        ASM("    .align 4");
        ASM(label + ":    .space 4");
        ASM("   .text");
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
        ASM1("# Grab ID: " + root->attribute->literal)
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
                ASM1("lw    $a0, " + std::to_string(12 + 4 * root->id_record->stackPosition) + "($fp)");
            }
        }
        ASM1("# ID grabbed");
        EMPTY_LINE;
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
        for (int i = 0; i < num_local; i++)
        {
            ASM1("subu  $sp, $sp, 4");
        }
        /**
         *                 <- SP
         *  local variables
         *  previous FP pointed address
         *  return address
         *  params
         *         <- FP
         */

        ASM1("# function setup")
        ASM1("sw    $ra, 0($sp)");
        ASM1("subu  $sp, $sp, 4");

        ASM1("sw    $fp, 0($sp)");
        ASM1("subu  $sp, $sp, 4");

        // store old FP
        ASM1("move  $fp, $sp");

        // generate code for the function block
        GenCode(Child(root, 3));

        ASM1("lw     $fp, 4($sp)");
        ASM1("addiu  $sp, $sp, 4");
        // load back the return address
        ASM1("lw     $ra, 4($sp)");
        ASM1("addiu  $sp, $sp, 4");
        // shrink the stack
        ASM1("addiu  $sp, $sp, " + std::to_string(num_local * 4));

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

        ASM1("# Begin of Function Declaration: " + ChildLiteral(root, 1));
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

        // store return address
        ASM1("sw    $ra, 0($sp)");
        ASM1("subu  $sp, $sp,4");
        // store old FP
        ASM1("sw    $fp, 0($sp)");
        ASM1("subu  $sp, $sp,4");

        ASM1("move  $fp, $sp");

        // generate code for the function block
        GenCode(Child(root, 3));

        // load back FP
        ASM1("lw    $fp, 4($sp)");
        ASM1("addiu $sp, $sp, 4");
        // load back the return address
        ASM1("lw    $ra, 4($sp)");
        ASM1("addiu $sp, $sp, 4");

        // shrink the stack
        ASM1("addiu  $sp, $sp, " + std::to_string((num_params + num_local) * 4));

        // jump return
        ASM1("jr    $ra");

        ASM1("# End of Function Declaration:" + ChildLiteral(root, 1));
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
        ASM1("# Function Call Setup:" + ChildLiteral(root, 0))

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

        if (ChildLiteral(root, 0) == "prints")
        {
            ASM1("li    $a0, 0");
            ASM1("sw    $a0, 0($sp)");
            ASM1("subu  $sp, $sp, 4");

            GenCode(Child(root, 1)->children[0]);
            ASM1("sw    $a0, 0($sp)");
            ASM1("subu  $sp, $sp, 4");

            ASM1("li    $a0, " + std::to_string(Child(Child(root, 1), 0)->attribute->literal_length));
            ASM1("sw    $a0, 0($sp)");
            ASM1("subu  $sp, $sp, 4");
        }
        else
        {
            // for every actual, push on the stack but backwards
            for (int i = Child(root, 1)->children.size() - 1; i >= 0; i--)
            {
                ASM1("# Create Actuals")
                ASM1("subu  $sp, $sp, 4");
            }

            for (int i = 0; i < Child(root, 1)->children.size(); i++)
            {
                GenCode(Child(root, 1)->children[i]);
                ASM1("sw    $a0," + std::to_string(4 + 4 * i) + "($sp)");
            }
        }

        // look up the function label
        std::string function_label = FuncLabel.find(ChildLiteral(root, 0))->second;
        // jump and link
        ASM1("jal   " + function_label);
        EMPTY_LINE;
        EMPTY_LINE;
    }
}

// Put a number on the top of the stack
void GenNumber(AST *root)
{
    if (root->type == NodeType::NUMBER)
    {
        ASM1("# Generate Number: " + root->attribute->literal)
        ASM1("li    $a0, " + root->attribute->literal); // load the literal
        EMPTY_LINE;
    }
}

// Put a bool on the top of the stack
void GenBoolean(AST *root)
{
    if (root->type == NodeType::TRUE)
    {
        ASM1("# Generate Boolean: True");
        ASM1("li    $a0, 1"); // true
        EMPTY_LINE;
    }
    if (root->type == NodeType::FALSE)
    {
        ASM1("# Generate Boolean: False");
        ASM1("li    $a0, 0"); // false
        EMPTY_LINE;
    }
}

void GenString(AST *root)
{
    if (root->type == NodeType::STRING)
    {

        std::string str_label = GenLabel();
        // create new string data
        ASM1("  .data");
        ASM1("  .align 4");

        std::string str_literal = str_label + ": .word";

        int i = 0;
        int j = 0;
        while (i < root->attribute->literal_length)
        {
            if (root->attribute->literal[i] == '\\' && i + 1 < root->attribute->literal_length)
            {
                switch (root->attribute->literal[i + 1])
                {
                case 'b':
                    str_literal += " " + std::to_string(8);
                    break;
                case 'f':
                    str_literal += " " + std::to_string(12);
                    break;
                case 't':
                    str_literal += " " + std::to_string(9);
                    break;
                case 'r':
                    str_literal += " " + std::to_string(13);
                    break;
                case 'n':
                    str_literal += " " + std::to_string(10);
                    break;
                case '\'':
                    str_literal += " " + std::to_string(39);
                    break;
                case '\"':
                    str_literal += " " + std::to_string(34);
                    break;
                case '\\':
                    str_literal += " " + std::to_string(92);
                    break;
                default:
                    str_literal += " " + std::to_string((int)root->attribute->literal[i]);
                    i--;
                    break;
                }
                i += 2;
                j++;
            }
            else
            {
                str_literal += " " + std::to_string((int)root->attribute->literal[i]);
                i++;
                j++;
            }
        }

        root->attribute->literal_length = j;

        ASM1(str_literal);
        // back to text
        ASM1("  .text");

        // load onto the top of the stack
        ASM1("la    $a0," + str_label);
        EMPTY_LINE;
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
        ASM1("# Generate IF-ELSE block: " + true_label + ", " + false_label + ", " + end_label);
        // branch check
        ASM1("bne   $a0, 1, " + false_label);
        ASM1("j     " + true_label);
        // if failed, goes in to false_label
        ASM(false_label + ":");
        // gen code for the code inside the label;
        GenCode(Child(root, 2));
        // skip true label
        ASM1("j     " + end_label);

        // true label
        ASM(true_label + ":");
        GenCode(Child(root, 1));

        // just keep it empty
        ASM(end_label + ":");

        EMPTY_LINE;
    }

    if (root->type == NodeType::IF)
    {

        GenCode(Child(root, 0));
        std::string true_label = GenLabel();
        std::string end_label = GenLabel();

        ASM1("# Generate IF block: " + end_label);
        // branch check
        ASM1("bne   $a0, 0, " + true_label);
        ASM1("j     " + end_label);
        ASM1(true_label + ":");
        // otherwise, true, do this
        GenCode(Child(root, 1));
        // just keep it empty
        ASM(end_label + ":");
        EMPTY_LINE;
    }
}

void GenBreak(AST *root)
{
    if (root->type == NodeType::BREAK)
    {
        while (root->type != NodeType::WHILE)
        {
            root = root->parent;
        }

        ASM1("# Generate Break: " + root->break_label);
        ASM1("j     " + root->break_label);
        EMPTY_LINE;
    }
}

void GenWhile(AST *root)
{
    if (root->type == NodeType::WHILE)
    {

        std::string test_label = GenLabel();
        std::string body_label = GenLabel();
        std::string end_label = GenLabel();

        // ASM1("# Generate WHILE block: " + test_label + ", " + body_label + ", " + end_label);

        root->break_label = end_label;

        ASM1("# WHILE TEST");
        ASM(test_label + ":");
        GenCode(Child(root, 0));

        ASM1("# WHILE BODY");
        // branch check
        ASM1("bne   $a0, 0, " + body_label);
        ASM1("j " + end_label);

        // if failed, goes in to false_label
        ASM(body_label + ":");
        // gen code for the code inside the label;
        GenCode(Child(root, 1));
        // skip true label
        ASM1("j     " + test_label);
        // just keep it empty
        ASM1("# WHILE END");
        ASM(end_label + ":");

        EMPTY_LINE;
    }
}

// the result would be register $a0
void GenExpr(AST *root)
{
    if (root->type == NodeType::BIN_ARITHMETIC || root->type == NodeType::BIN_RELATION || root->type == NodeType::EQUIVALENCE)
    {
        ASM1("# Evaluate a binary expression, return will be in $a0");
        GenCode(Child(root, 0)); // get lhs
        ASM1("sw    $a0, 0($sp)");
        ASM1("subu  $sp, $sp, 4"); // tempory store on the stack
        GenCode(Child(root, 1));   // get rhs

        ASM1("lw    $t0, 4($sp)"); // lhs on the temp 1
        ASM1("addiu  $sp, $sp, 4") // restore the stack

        std::string op_label = BinaryInstruction.find(root->symbol)->second;
        if (op_label == "div")
        {
            std::string end_label = GenLabel();
            ASM1("bne   $a0, 0, " + end_label);
            ASM1("j     div0");
            ASM1(end_label + ":");
        }
        // store result on the $a0
        ASM1(op_label + "    $a0, $t0,$a0 "); // the result is on the temp 0
        EMPTY_LINE;
    }

    if (root->type == NodeType::BIN_LOGIC)
    {
        ASM1("# Evaluate a binary logic, return will be in $a0");
        std::string op_label = BinaryInstruction.find(root->symbol)->second;
        std::string keep_eval_label = GenLabel();
        std::string end_label = GenLabel();
        GenCode(Child(root, 0)); // get lhs
        if (root->symbol == "&&")
        {
            // if LHS is true, keep evaluting RHS
            ASM1("bne   $a0, 0, "+keep_eval_label);
            // otherwise, return LHS <=> FALSE
            ASM1("j     "+end_label);
        }
        else if (root->symbol == "||")
        {
            // if LHS is false, keep evaluting RHS
            ASM1("bne   $a0, 1, "+keep_eval_label);
            // otherwise, return LHS <=> TRUE
            ASM1("j     "+end_label);
        }
        // keep evaluating, the result should be equal to the RHS if enter
        ASM1(keep_eval_label+":");
        GenCode(Child(root,1));
        ASM1(end_label+":");
        EMPTY_LINE;
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
            ASM1("sw    $a0, " + std::to_string(12 + 4 * root->children[0]->id_record->stackPosition) + "($fp)");
        }
        EMPTY_LINE;
    }

    if (root->type == NodeType::UN_ARITHMETIC)
    {
        ASM1("# unary arithmetic -");
        GenCode(Child(root, 0));
        ASM1("negu  $a0, $a0");
        EMPTY_LINE;
    }

    if (root->type == NodeType::UN_LOGIC)
    {
        ASM1("# unary logic !");
        GenCode(Child(root, 0));
        ASM1("xori  $a0, $a0,1");
        EMPTY_LINE;
    }

    if (root->type == NodeType::RETURN)
    {

        ASM1("# RETURN");
        if (!root->children.empty())
        {
            GenCode(root->children[0]);
        }
        // load back the FP
        ASM1("lw    $fp, 4($sp)");
        ASM1("addiu  $sp, $sp, 4");
        // load back the return address
        ASM1("lw    $ra, 4($sp)");
        ASM1("addiu  $sp, $sp, 4");
        // shrink the stack
        ASM1("addiu  $sp, $sp, " + std::to_string(numLocal(root) * 4));

        // jump return
        ASM1("jr    $ra");
        EMPTY_LINE;
    }
}

int numLocal(AST *root)
{
    while (root->type != NodeType::FUNC_DEC)
    {
        root = root->parent;
    }
    return SYMBOL_TABLE.find(ChildLiteral(root, 1))->second.size();
}
/**
 * @brief Generate a new label and return
 *
 * @return std::string, the new label
 */
std::string GenLabel()
{
    label_count++;
    return "Label_" + std::to_string(label_count - 1);
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

    // div by zero error
    ASM1(".data");
    ASM1(".align 4");
    ASM1("div_by_zero: .asciiz \"Exception: div by zero......\n\"");
    ASM1(".text")
    ASM("div0:")
    ASM1("la    $a0, div_by_zero");
    ASM1("li    $v0, 4");
    ASM1("syscall")
    ASM1("li    $v0, 10");
    ASM1("syscall");

    // print int
    ASM1(".text");
    ASM("printi:");

    // store return address
    ASM1("sw    $ra, 0($sp)");
    ASM1("subu  $sp, $sp,4");
    // store old FP
    ASM1("sw    $fp, 0($sp)");
    ASM1("subu  $sp, $sp,4");

    ASM1("move  $fp, $sp");

    ASM1("lw    $a0, 12($fp)");
    ASM1("li    $v0, 1");
    ASM1("syscall");

    // load back the FP
    ASM1("lw     $fp, 4($sp)");
    ASM1("addiu  $sp, $sp, 4");

    // load back the return address
    ASM1("lw     $ra, 4($sp)");
    ASM1("addiu  $sp, $sp, 4");

    // shrink the stack
    ASM1("addiu  $sp, $sp, 4");
    // jump return
    ASM1("jr    $ra");

    EMPTY_LINE;
    EMPTY_LINE;

    // print string
    ASM("prints:");

    ASM1("sw    $ra, 0($sp)");
    ASM1("subu  $sp, $sp,4");
    ASM1("sw    $fp, 0($sp)");
    ASM1("subu  $sp, $sp,4");

    ASM("ps_test:");
    ASM1("lw  $t0, 20($sp)");
    ASM1("lw  $t1, 12($sp)");
    ASM1("bge $t0, $t1, ps_end");

    ASM("ps_body:");
    ASM1("lw  $a0, 16($sp)");
    ASM1("lw  $t0, 20($sp)");
    ASM1("mul $t0, $t0, 4");

    ASM1("addu $a0, $a0, $t0");

    ASM1("lw  $a0, 0($a0)");
    ASM1("li  $v0, 11");
    ASM1("syscall");

    ASM1("lw  $t0, 20($sp)");
    ASM1("addiu $t0, 1");
    ASM1("sw  $t0, 20($sp)");
    ASM1("j   ps_test");

    ASM("ps_end:")

    // load back the FP
    ASM1("lw     $fp, 4($sp)");
    ASM1("addiu  $sp, $sp, 4");

    // load back the return address
    ASM1("lw     $ra,  4($sp)");
    ASM1("addiu  $sp, $sp, 4");

    // shrink the stack
    ASM1("addiu  $sp, $sp, 12");
    // jump return
    ASM1("jr    $ra");

    EMPTY_LINE;
    EMPTY_LINE;

    // print char
    ASM("printc:");

    ASM1("sw    $ra, 0($sp)");
    ASM1("subu  $sp, $sp,4");
    ASM1("sw    $fp, 0($sp)");
    ASM1("subu  $sp, $sp,4");

    ASM1("move  $fp, $sp");

    ASM1("lw    $a0, 12($fp)");
    // ASM1("subu  $a0, 32");
    ASM1("li    $v0, 11");
    ASM1("syscall");

    // load back the FP
    ASM1("lw     $fp, 4($sp)");
    ASM1("addiu  $sp, $sp, 4");

    // load back the return address
    ASM1("lw     $ra, 4($sp)");
    ASM1("addiu  $sp, $sp, 4");
    // shrink the stack
    ASM1("addiu  $sp, $sp, 4");
    // jump return
    ASM1("jr    $ra");

    EMPTY_LINE;
    EMPTY_LINE;

    // printb
    {
        ASM1(".data");
        ASM1(".align 4");
        ASM("true_label:    .asciiz \"true\"");
        ASM("false_label:   .asciiz \"false\"");
        ASM1(".text");
        ASM("printb:");

        ASM1("sw    $ra, 0($sp)");
        ASM1("subu  $sp, $sp,4");
        ASM1("sw    $fp, 0($sp)");
        ASM1("subu  $sp, $sp,4");

        ASM1("move  $fp, $sp");

        std::string true_label = GenLabel();
        std::string false_label = GenLabel();
        std::string end_label = GenLabel();

        ASM1("lw    $a0, 12($fp)");
        ASM1("beq   $a0, 0, " + false_label);

        ASM1(true_label + ":");
        ASM1("la    $a0, true_label");
        ASM1("j     " + end_label);

        ASM1(false_label + ":");
        ASM1("la    $a0, false_label");

        ASM1(end_label + ":");
        ASM1("li    $v0, 4");
        ASM1("syscall");

        // load back the FP
        ASM1("lw     $fp, 4($sp)");
        ASM1("addiu  $sp, $sp, 4");

        // load back the return address
        ASM1("lw     $ra, 4($sp)");
        ASM1("addiu  $sp, $sp, 4");
        // shrink the stack
        ASM1("addiu  $sp, $sp, 4");
        // jump return
        ASM1("jr    $ra");
    }
    EMPTY_LINE;
    EMPTY_LINE;

    // getchar
    {
        ASM1(".data");
        ASM1(".align 4")
        ASM1("buffer:   .space 4");

        ASM1(".text");
        ASM("getchar:");
        ASM1("sw    $ra, 0($sp)");
        ASM1("subu  $sp, $sp,4");
        ASM1("sw    $fp, 0($sp)");
        ASM1("subu  $sp, $sp,4");

        ASM1("move  $fp, $sp");

        // read character by read string......
        ASM1("la    $a0, buffer");
        ASM1("la    $a1, 2");
        ASM1("li    $v0, 8");
        ASM1("syscall");

        std::string eof = GenLabel();
        std::string end = GenLabel();

        // move to $a0
        ASM1("lw    $a0, 0($a0)");
        ASM1("beq   $a0, 0, " + eof);
        ASM1("j     " + end);
        ASM(eof + ":");
        ASM1("li    $a0, -1");

        ASM(end + ":");
        // load back the FP
        ASM1("lw     $fp, 4($sp)");
        ASM1("addiu  $sp, $sp, 4");

        // load back the return address
        ASM1("lw     $ra, 4($sp)");
        ASM1("addiu  $sp, $sp, 4");
        // jump return
        ASM1("jr    $ra");
    }
    // the function

    ASM1("# End of predefined functions")

    EMPTY_LINE;
    EMPTY_LINE;
}

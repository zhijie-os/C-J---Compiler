#include "codeGen.h"
#include "semantic.h"

#define ASM(x) std::cout << x << std::endl;
#define ASM1(x) std::cout <<"   "<< x << std::endl;
#define ASM2(x) std::cout <<"       "<< x << std::endl;
#define EMPTY_LINE  std::cout << std::endl;

#define DATA_SIZE 4

int label_count = 0;

void yycodegen(AST *root)
{
    GenGlobalVar(root);
    GenText();

    for(auto c:root->children)
    {
        if(c->type==NodeType::MAIN_DEC)
        {
            GenMain(c);
        }
        if(c->type==NodeType::FUNC_DEC)
        {
            GenFunc(c);
        }
    }   
}

void GenGlobalVar(AST *root)
{
    for (auto c : root->children)
    {
        if (c->type == NodeType::GLOBAL_VAR_DEC)
        {
            ASM("    .data");
            ASM("    .align 2");
            ASM(ChildLiteral(c,1)+":    .space 4");
            EMPTY_LINE;
        }
    }
}

void GenText()
{
    ASM("    .text");
    ASM("    .globl main");
    EMPTY_LINE;
}


void GenMain(AST *root)
{   
    ASM("main:");
    ASM("    li  $v0,10");
    ASM("    syscall");
    EMPTY_LINE;
}

/**
 * Assumption: the parameters are already pushed onto the stack, 
 * $a0 = the number of parameter on the stack 
 */
void GenFunc(AST *root)
{
    // figure out the number of parameters and number of local variables
    int num_params = GLOBAL_FUNC.find(ChildLiteral(root,1))->second.paramType.size();
    int num_local = SYMBOL_TABLE.find(ChildLiteral(root,1))->second.size() - num_params;

    // ASM1(".text")
    ASM(ChildLiteral(root,1)+":");
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
    ASM1("sw    $ra, 0($sp)");       // store on top of the stack         
    ASM1("subu  $sp, $sp, 4");    // expand stack

    // store FP
    ASM1("sw    $fp, 0($sp)");      // store on top of the stack
    ASM1("subu  $sp, $sp, 4");    // expand stack

    // calculate the new FP address
    
    // # of paramter * 4 + 4 + 4
    ASM1("li    $t0, 4");         // each variable is 4 bytes
    ASM1("mul   $t0, $t0, "+std::to_string(num_params)); //  size of  the parameters 
    ASM1("addu  $t0, $t0, 8");    // skip Parameters + Return Address + Function Pointer
    ASM1("addu  $fp, $sp, $t0");  // reset the FP to the beginning
    


    // # of local * 4
    ASM1("li    $t0, 4");        // each variable is 4 bytes
    ASM1("mul   $t0, $t0, " + std::to_string(num_local));  // locals
    ASM1("subu  $fp, $sp, $t0")   // expand stack for local variables


    // GenBlock(Child(root,3));

    EMPTY_LINE;EMPTY_LINE;
    ASM1("# function teardown");
    // function exit and return
    ASM1("lw    $ra, "+std::to_string(num_params*DATA_SIZE)+"($fp)");    // load back the RA
    ASM1("move  $t0, $fp");         // the beginning of the frame
    ASM1("lw    $ra, "+std::to_string(num_params*DATA_SIZE)+"($fp)");   // load back the FP
    ASM1("move  $sp, $t0");        // pop off the stack frame
    ASM1("jr    $ra");          // return 

    EMPTY_LINE;
}

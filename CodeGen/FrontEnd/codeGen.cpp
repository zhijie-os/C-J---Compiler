#include "codeGen.h"
#include "semantic.h"

#define ASM(x) std::cout << x << std::endl;
#define EMPTY_LINE  std::cout << std::endl;    

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
    ASM(".text")
    ASM(ChildLiteral(root,1)+":");
    /**
     *                 <- SP
     *  local variables
     *  previous FP pointed address
     *  return address 
     *  params 
     *         <- FP 
     */

    // store return address
    ASM("sw $ra,0($sp)");
    ASM("subu $sp, $sp, 4");

    // store FP
    ASM("sw $fp, 0($sp)");
    ASM("subu $sp, $sp, 4");

    // calculate the new FP address
    
    // # of paramter * 4 + 4 + 4
    ASM("li   $t0, 4");
    ASM("mul  $t0, $t0, $a0");
    ASM("addu $t0, $t0, 8");
    ASM("addu $fp, $sp, $t0");
    
    int num_local = CountLocal(root);

    // # of local * 4
    ASM("li   $t0, 4");
    ASM("mul  $t0, $t0," + std::to_string(num_local));
    ASM("addu $fp, $sp, $t0")


    // load back the RA and FP
    ASM("lw   $ra, -4($fp)")

    EMPTY_LINE;
}

int CountLocal(AST* root)
{
    int num_local=0;

    if(root->type==NodeType::VAR_DEC)
    {
        num_local++;
    }

    for(auto c: root->children)
    {
        num_local+=CountLocal(c);
    }

    return num_local;
}
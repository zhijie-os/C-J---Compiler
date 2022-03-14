%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "parser.h"
    #include "AST.h"
%}


%defines "parser.bison.h"
%output "parser.bison.cpp"
%expect 0
%define api.value.type {AST *}

%token  NUMBER STRING_Y TRUE FALSE BOOLEAN INT ID VOID BREAK RETURN IF ELSE WHILE LE GE NE EQ AND OR



%%

dummy_start     : NUMBER        {$1->PrettyPrint(0);}             
                | dummy_start NUMBER  {$2->PrettyPrint(0);}
                ;
%%
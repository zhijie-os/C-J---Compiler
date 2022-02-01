%option noyywrap

%{
    #include "scanner.h"

    int num_error=0;
    int line_num=1;
    int num_tokens=0;
    int array_size=2;
    
    struct TOKEN *tokens;
%}

%x COMMENT
%x STRING

/* regular definition */


delim   [ \t\r]
ws      {delim}+
letter  [A-Za-z]
letter_ [A-Za-z_]
digit   [0-9]
id      {letter_}({letter_}|{digit})*
number  {digit}+

 


%% 

"\""                                    {BEGIN(STRING);}
<STRING>(\\.|[^"\\\r\n<<EOF>>])*        {scan_general(STRING);}
<STRING>"\""                            {BEGIN(0);}
<STRING>\\[^bftrn'"\\]                  {printf("unable to escape");error_string();}
<STRING>\n                              {printf("LF");error_string();}
<STRING>\r                              {printf("CR");error_string();}
<STRING><<EOF>>                         {printf("EOF");error_string();}


"//"                                    {BEGIN(COMMENT);}
<COMMENT>[^\r\n]                        {/* eats up the comment */};
<COMMENT>\n                             {line_num++;BEGIN(0);}
<COMMENT>[\r<<EOF>>]                    {BEGIN(0);}



\n          {line_num++;}
{ws}        {/* ignore whitespaces */}
true        {scan_reserved(TRUE);}
false       {scan_reserved(FALSE);}
boolean     {scan_reserved(BOOLEAN);}
int         {scan_reserved(INT);}
void        {scan_reserved(VOID);}
if          {scan_reserved(IF);}
else        {scan_reserved(ELSE);}
while       {scan_reserved(WHILE);}
break       {scan_reserved(BREAK);}
return      {scan_reserved(RETURN);}
"+"         {scan_reserved(OP_ADD);}
"-"         {scan_reserved(OP_SUB);}
"*"         {scan_reserved(OP_MUL);}
"/"         {scan_reserved(OP_DIV);}
"%"         {scan_reserved(OP_MOD);}
"<"         {scan_reserved(OP_LT);}
">"         {scan_reserved(OP_GT);}
"<="        {scan_reserved(OP_LE);}
">="        {scan_reserved(OP_GE);}
"=="        {scan_reserved(OP_EQ);}
"!="        {scan_reserved(OP_NE);}
"="         {scan_reserved(OP_ASSIGN);}
"!"         {scan_reserved(OP_NOT);}
"&&"        {scan_reserved(OP_AND);}
"||"        {scan_reserved(OP_OR);}
"("         {scan_reserved(L_PAR);}
")"         {scan_reserved(R_PAR);}
"{"         {scan_reserved(L_BRA);}
"}"         {scan_reserved(R_BRA);}
";"         {scan_reserved(SMCOL);}
","         {scan_reserved(COMMA);}
{number}    {scan_general(NUMBER);}
{id}        {scan_general(ID);}

.           {error_general();}


%%



int main(int argc, char *argv[])
{
    tokens=(struct TOKEN *)malloc(array_size*sizeof(struct TOKEN));
    if(argc==2)
    {
        yyin = fopen(argv[1],"r");
        if(yyin==NULL)
        {
            fprintf(stderr, "Faile to open %s\n",argv[1]);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        perror("Usage:./lexer <file path>\n");
        exit(EXIT_FAILURE);
    }

    yylex();

    if(num_tokens>0)
        print_tokens();
    free(tokens);
}



%{
    enum TOKEN{
        ID = 1,
        STRING, 
        NUMBER, TRUE, FALSE, BOOLEAN, INT, VOID, 
        IF, ELSE, WHILE, BREAK, RETURN,
        OP_ADD, OP_SUB, OP_MUL, OP_DIV, OP_MOD,
        OP_LT, OP_GT, OP_LE, OP_GE, OP_EQ, OP_NE,
        OP_ASSIGN,
        OP_NOT, OP_AND, OP_OR,
        L_PAR, R_PAR, L_BRA, R_BRA,
        SMCOL, COMMA,
    };

    int num_error=0;
    int num_line=1;
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
<STRING>(\\.|[^"\\\r\n<<EOF>>])*        {printString();}
<STRING>"\""                            {BEGIN(0);}
<STRING>[\r\n]                          {errorString();}
<STRING><<EOF>>                         {errorString();}


"//"                                    {BEGIN(COMMENT);}
<COMMENT>[^\r\n]                        {/* eats up the comment */};
<COMMENT>[\r\n<<EOF>>]                  {BEGIN(0);}



\n          {++num_line;}
{ws}        {/* ignore whitespaces */}
true        {printToken(TRUE,1);}
false       {printToken(FALSE,1);}
boolean     {printToken(BOOLEAN,1);}
int         {printToken(INT,1);}
void        {printToken(VOID,1);}
if          {printToken(IF,1);}
else        {printToken(ELSE,1);}
while       {printToken(WHILE,1);}
break       {printToken(BREAK,1);}
return      {printToken(RETURN,1);}
"+"         {printToken(OP_ADD,1);}
"-"         {printToken(OP_SUB,1);}
"*"         {printToken(OP_MUL,1);}
"/"         {printToken(OP_DIV,1);}
"%"         {printToken(OP_MOD,1);}
"<"         {printToken(OP_LT,1);}
">"         {printToken(OP_GT,1);}
"<="        {printToken(OP_LE,1);}
">="        {printToken(OP_GE,1);}
"=="        {printToken(OP_EQ,1);}
"!="        {printToken(OP_NE,1);}
"="         {printToken(OP_ASSIGN,1);}
"!"         {printToken(OP_NOT,1);}
"&&"        {printToken(OP_AND,1);}
"||"        {printToken(OP_OR,1);}
"("         {printToken(L_PAR,1);}
")"         {printToken(R_PAR,1);}
"{"         {printToken(L_BRA,1);}
"}"         {printToken(R_BRA,1);}
";"         {printToken(SMCOL,1);}
","         {printToken(COMMA,1);}
{number}    {printToken(NUMBER,0);}
{id}        {printToken(ID,0);}

.           {errorHandle();}


%%

void errorString()
{

    fprintf(stderr,"error: string missing closing quote at or near line %d\n",num_line);
    exit(EXIT_FAILURE);
}


void printString()
{
    char buff[yyleng+1];
    memset(buff,0,yyleng+1);

    int j=0;
    for(int i=0;i<yyleng;i++)
    {
        if(yytext[i]!='\0')
        {
            buff[j]=yytext[i];
            j++;
        }
    }

    printf("Token(string, %d, %s) ",num_line, buff);
}

void errorHandle()
{
    fprintf(stderr,"warning: ignoring bad character at or near line %d \n",num_line);
    num_error ++;
    if(num_error>=10)
    {
        printf("Too many errors, abort....\n");
        exit(EXIT_FAILURE);
    }
}

void printToken(int tk, int reserved)
{
    char name[20];
    memset(&name,0,20);

    switch(tk)
    {
        case ID:
            strcpy(name,"id");
            break;
        case STRING:
            strcpy(name,"string");
            break;
        case NUMBER:
            strcpy(name,"number");
            break;
        case TRUE:
            strcpy(name,"true");
            break;
        case FALSE:
            strcpy(name,"false");
            break;  
        case BOOLEAN:
            strcpy(name,"boolean");
            break;  
        case INT:
            strcpy(name,"int");
            break;  
        case VOID:
            strcpy(name,"void");
            break;  
        case IF:
            strcpy(name,"if");
            break;  
        case ELSE:
            strcpy(name,"else");
            break;  
        case WHILE:
            strcpy(name,"while");
            break;  
        case BREAK:
            strcpy(name,"break");
            break;  
        case RETURN:
            strcpy(name,"return");
            break;  
        case OP_ADD:
            strcpy(name,"+");
            break;  
        case OP_SUB:
            strcpy(name,"-");
            break;  
        case OP_MUL:
            strcpy(name,"*");
            break;  
        case OP_DIV:
            strcpy(name,"/");
            break;  
        case OP_MOD:
            strcpy(name,"%");
            break;  
        case OP_LT:
            strcpy(name,"<");
            break; 
        case OP_GT:
            strcpy(name,">");
            break; 
        case OP_LE:
            strcpy(name,"<=");
            break; 
        case OP_GE:
            strcpy(name,">=");
            break; 
        case OP_EQ:
            strcpy(name,"=");
            break;
        case OP_NE:
            strcpy(name,"!=");
            break; 
        case OP_ASSIGN:
            strcpy(name,"=");
            break; 
        case OP_NOT:
            strcpy(name,"!");
            break; 
        case OP_AND:
            strcpy(name,"&&");
            break; 
        case OP_OR:
            strcpy(name,"||");
            break; 
        case L_PAR:
            strcpy(name,"(");
            break; 
        case R_PAR:
            strcpy(name,")");
            break; 
        case L_BRA:
            strcpy(name,"{");
            break;  
        case R_BRA:
            strcpy(name,"}");
            break; 
        case SMCOL:
            strcpy(name,";");
            break; 
        case COMMA:
            strcpy(name,",");
            break; 
    }

    if(reserved)
    {
        printf("Token(%s, %d, None)  ", name, num_line);
    }
    else 
    {
        printf("Token(%s, %d, %s)  ", name, num_line, yytext);
    }
}


int main(int argc, char *argv[])
{
    if(argc==2)
    {
        yyin = fopen(argv[1],"r");
        if(fopen==NULL)
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
}


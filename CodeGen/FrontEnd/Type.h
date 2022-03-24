#pragma once

enum class NodeType
{
    PROGRAM,
    GLOBAL_VAR_DEC,
    VAR_DEC,
    FUNC_DEC,
    MAIN_DEC,
    FORMALS,
    FORMAL,
    ACTUALS,
    ACTUAL,
    VOID,
    BLOCK,
    NULL_STMT,
    STMT_EXPR,
    IF,
    IF_ELSE,
    TRUE,
    FALSE,
    WHILE,
    FUNC_CALL,
    BIN_ARITHMETIC,
    BIN_RELATION,
    UN_ARITHMETIC,
    BIN_LOGIC,
    UN_LOGIC,
    ASSIGN,
    INT,
    RETURN,
    BREAK,
    BOOLEAN,
    NUMBER,
    STRING,
    IDENTIFIER,
    DUMMY,
};


enum class DataType
{
    INT,
    BOOL,
    STRING,
    VOID,
};





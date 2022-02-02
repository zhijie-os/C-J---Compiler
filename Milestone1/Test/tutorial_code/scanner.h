/********************************
 * Example C Lexical Analyzer
 * Written for CPSC 411 Tutorial
 * File: scanner.h
 * Shankar Ganesh
 * *****************************/

#ifndef SCANNER_H
#define SCANNER_H

#include <stdio.h>

enum {
    T_ID = 1,
    T_BEGIN,
    T_END,
    T_NUM,
    T_ADD,
    T_SUB,
    T_DIV,
    T_MULT,
    T_LT,
    T_GT,
    T_GE,
    T_LE
};

extern int yylex();
extern FILE *yyin;
extern int yylineno;
extern char* yytext;

#endif
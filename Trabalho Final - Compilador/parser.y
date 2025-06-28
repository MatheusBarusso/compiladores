%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"
int yylex(void);
int yyerror(const char *s);
%}

%union {
    int num;
    char *id;
}

%token IF ELSE WHILE FOR INT PRINT READ RETURN MAIN
%token PLUS MINUS TIMES DIVIDE ASSIGN LE GE EQ NE
%token MOD AND OR NOT
%token <num> NUMBER
%token <id> IDENTIFIER
%token STRING_TYPE
%token <id> STRING_LITERAL

%right NOT
%left TIMES DIVIDE MOD
%left PLUS MINUS
%left LE GE EQ NE '<' '>'
%left AND
%left OR

%%

program:
    | program external_decl
    ;

external_decl:
    MAIN '(' ')' block
  | IDENTIFIER '(' ')' block
  | statement
    ;

block:
    '{' statement_list '}'
    ;

statement_list:
    | statement_list statement
    ;

for_init:
    | IDENTIFIER ASSIGN expression
    ;

for_update:
    | IDENTIFIER ASSIGN expression
    ;

argument_list:
    expression
  | argument_list ',' expression
    ;

statement:
    INT IDENTIFIER ';'
  | INT IDENTIFIER '[' NUMBER ']' ';'
  | INT IDENTIFIER '[' NUMBER ']' ASSIGN '{' expression_list '}' ';'
  | STRING_TYPE IDENTIFIER ';'
  | STRING_TYPE IDENTIFIER ASSIGN STRING_LITERAL ';'
  | IDENTIFIER ASSIGN expression ';'
  | IDENTIFIER '(' ')' ';'
  | IDENTIFIER '[' expression ']' ASSIGN expression ';'
  | IDENTIFIER '(' argument_list ')' ';'
  | IF '(' expression ')' block
  | IF '(' expression ')' block ELSE block
  | FOR '(' for_init ';' expression ';' for_update ')' block
  | WHILE '(' expression ')' block
  | PRINT '(' argument_list ')' ';'
  | READ '(' argument_list ')' ';'
  | RETURN expression ';'
    ;

expression_list:
      expression
    | expression_list ',' expression
    ;

expression:
    expression PLUS expression
  | expression MINUS expression
  | expression TIMES expression
  | expression DIVIDE expression
  | expression MOD expression
  | expression LE expression
  | expression GE expression
  | expression EQ expression
  | expression NE expression
  | expression '<' expression
  | expression '>' expression
  | expression AND expression
  | expression OR expression
  | NOT expression
  | '(' expression ')'
  | IDENTIFIER '[' expression ']'
  | NUMBER
  | IDENTIFIER
  | STRING_LITERAL
    ;

%%

int yyerror(const char *s) {
    fprintf(stderr, "Erro sintático: %s\n", s);
    return 0;
}

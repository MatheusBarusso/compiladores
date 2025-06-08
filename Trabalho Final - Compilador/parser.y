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
%token <num> NUMBER
%token <id> IDENTIFIER

%left LE GE EQ NE '<' '>'
%left PLUS MINUS
%left TIMES DIVIDE

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
  | IDENTIFIER ASSIGN expression ';'
  | IDENTIFIER '(' ')' ';'
  | IDENTIFIER '(' argument_list ')' ';'
  | IF '(' expression ')' block
  | IF '(' expression ')' block ELSE block
  | FOR '(' for_init ';' expression ';' for_update ')' block
  | WHILE '(' expression ')' block
  | PRINT '(' argument_list ')' ';'
  | READ '(' argument_list ')' ';'
  | RETURN expression ';'
    ;

expression:
    expression PLUS expression
  | expression MINUS expression
  | expression TIMES expression
  | expression DIVIDE expression
  | expression LE expression
  | expression GE expression
  | expression EQ expression
  | expression NE expression
  | expression '<' expression
  | expression '>' expression
  | '(' expression ')'
  | NUMBER
  | IDENTIFIER
    ;

%%

int yyerror(const char *s) {
    fprintf(stderr, "Erro sintático: %s\n", s);
    return 0;
}

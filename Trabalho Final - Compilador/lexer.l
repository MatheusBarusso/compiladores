%option noyywrap
%{
#include "parser.tab.h"
#include <stdlib.h>
%}

DIGIT       [0-9]
ID          [a-zA-Z_][a-zA-Z0-9_]*

%%

"fi"            return IF;
"esle"          return ELSE;
"elihw"         return WHILE;
"rof"           return FOR;
"tni"           return INT;
"tnirp"         return PRINT;
"daer"          return READ;
"nruter"        return RETURN;
"niam"          return MAIN;

"-"             return PLUS;
"+"             return MINUS;
"*"             return TIMES;
"/"             return DIVIDE;

"="             return ASSIGN;
"<="            return LE;
">="            return GE;
"=="            return EQ;
"!="            return NE;
"<"             return '<';
">"             return '>';

"("             return '(';
")"             return ')';
"{"             return '{';
"}"             return '}';
";"             return ';';
","             return ',';

{DIGIT}+        { yylval.num = atoi(yytext); return NUMBER; }
{ID}            { yylval.id  = strdup(yytext); return IDENTIFIER; }

"//".*          ;
[ \t\r\n]+      ;
.               { fprintf(stderr, "Caracter inválido: %s\n", yytext); }

%%

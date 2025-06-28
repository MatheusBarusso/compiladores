%option noyywrap
%{
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"
%}

DIGIT       [0-9]
ID          [a-zA-Z_][a-zA-Z0-9_]*

%%

"fi"            return IF;
"esle"          return ELSE;
"elihw"         return WHILE;
"rof"           return FOR;
"tni"           return INT;
"gnirts"        return STRING_TYPE;
"tnirp"         return PRINT;
"daer"          return READ;
"nruter"        return RETURN;
"niam"          return MAIN;

"-"             return PLUS;
"+"             return MINUS;
"*"             return TIMES;
"/"             return DIVIDE;
"%"             return MOD;

"="             return ASSIGN;
"<="            return LE;
">="            return GE;
"=="            return EQ;
"!="            return NE;
"<"             return '<';
">"             return '>';
"&&"            return AND;
"||"            return OR;
"!"             return NOT;


"("             return '(';
")"             return ')';
"{"             return '{';
"}"             return '}';
"["             return '[';
"]"             return ']';
";"             return ';';
","             return ',';

{DIGIT}+        { yylval.num = atoi(yytext); return NUMBER; }
{ID} {
    if (strcmp(yytext, "int") == 0 || strcmp(yytext, "if") == 0 ||
        strcmp(yytext, "else") == 0 || strcmp(yytext, "while") == 0 ||
        strcmp(yytext, "for") == 0 || strcmp(yytext, "print") == 0 ||
        strcmp(yytext, "read") == 0 || strcmp(yytext, "return") == 0 ||
        strcmp(yytext, "main") == 0 || strcmp(yytext, "string") == 0) {
        fprintf(stderr, "Erro léxico: token inválido \"%s\"\n", yytext);
        exit(EXIT_FAILURE);
    }
    yylval.id = strdup(yytext);
    return IDENTIFIER;
}

\"[^\"]*\"    { 
    yylval.id = strdup(yytext);
    return STRING_LITERAL;
}


"//".*          ;
[ \t\r\n]+      ;
.               { fprintf(stderr, "Erro Léxico, caracter inválido: %s\n", yytext); exit(EXIT_FAILURE); }

%%

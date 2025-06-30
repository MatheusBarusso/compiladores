%{
#include "parser.tab.h"
#include <stdio.h>
%}

%option noyywrap

%%

"fi"            { return IF; }
"esle"          { return ELSE; }
"elihw"         { return WHILE; }
"rof"           { return FOR; }
"tni"           { return INT; }
"gnirts"        { return STRING; }
"tnirp"         { return PRINTF; }
"daer"          { return SCANF; }
"kaerb"         { return BREAK; }

"+"             { return MAIS; }
"-"             { return MENOS; }
"*"             { return MULT; }
"/"             { return DIV; }
"=="            { return IGUAL; }
"!="            { return DIFERENTE; }
"<"             { return MAIOR; }
">"             { return MENOR; }
"<="            { return MAIORIGUAL; }
">="            { return MENORIGUAL; }
"="             { return ATRIB; }
"&&"            { return AND; }
"||"            { return OR; }
","             { return COMENT; }

"{"             { return LCHAVE; }
"}"             { return RCHAVE; }
"["             { return LCOL; }
"]"             { return RCOL; }
";"             { return PEV; }
"("             { return LPAR; }
")"             { return RPAR; }

"\""[^"]*"\""    {yylval.str_val = strdup(yytext);return STRING;}

"//".* ;
[ \t\r\n]+      ;

[0-9]+ { 
	yylval.int_val = atoi(yytext);
	return NUM;
}
[a-zA-Z][a-zA-Z0-9_]* {
	yylval.str_val = strdup(yytext); 
   	return ID;
}

.               { printf("Erro Léxico, caracter inválido: %s\n", yytext); return ERRO; }
%%
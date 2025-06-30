%code requires {
#include <string>
#include <vector>
}

%{
#include <cstdio>
#include <cstdarg>
#include <map>
#include "parser.tab.h"

extern FILE *out;
extern std::string newTemp();
extern std::string newLabel();
extern std::string regOf(const std::string &);
extern void declareVar(const std::string &);
extern void declareArray(const std::string &, int);
extern void emit(const char *, ...);
extern std::string exprResult(const std::string &, int, const std::string &);
extern std::string condText(const std::string &);
extern FILE *yyin;
extern int yylex();
extern int yyparse();
int yyerror(const char *);
%}

%union {
    int num;
    char *id;
    std::string *str;
    std::vector<std::string> *strlist;
}

%token IF ELSE WHILE FOR INT PRINT READ RETURN MAIN
%token PLUS MINUS TIMES DIVIDE ASSIGN LE GE EQ NE MOD AND OR NOT
%token <num> NUMBER
%token <id> IDENTIFIER
%token STRING_TYPE
%token <id> STRING_LITERAL

%type <str>       expression
%type <strlist>   argument_list expression_list

%right NOT
%left TIMES DIVIDE MOD
%left PLUS MINUS
%left LE GE EQ NE '<' '>'
%left AND
%left OR
%nonassoc LOWER_THAN_ELSE

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
    | IDENTIFIER ASSIGN expression { emit("mov %s %s 0", regOf($1).c_str(), (*$3).c_str()); }
    ;

for_update:
    | IDENTIFIER ASSIGN expression { emit("mov %s %s 0", regOf($1).c_str(), (*$3).c_str()); }
    ;

argument_list:
      expression { $$ = new std::vector<std::string>(); $$->push_back(*$1); }
    | argument_list ',' expression { $1->push_back(*$3); $$ = $1; }
    ;

expression_list:
      expression { $$ = new std::vector<std::string>(); $$->push_back(*$1); }
    | expression_list ',' expression { $1->push_back(*$3); $$ = $1; }
    ;

statement:
      matched_stmt
    | unmatched_stmt
    ;

matched_stmt:
    block
  | INT IDENTIFIER ';'                                                    { declareVar($2); }
  | INT IDENTIFIER '[' NUMBER ']' ';'                                      { declareArray($2, $4); }
  | INT IDENTIFIER '[' NUMBER ']' ASSIGN '{' expression_list '}' ';'       {
        declareArray($2, $4);
        int idx = 0;
        for (auto &e : *$8) {
            std::string name = std::string($2) + "[" + std::to_string(idx++) + "]";
            emit("mov %s %s 0", regOf(name).c_str(), e.c_str());
        }
    }
  | STRING_TYPE IDENTIFIER ';'                                             { declareVar($2); }
  | STRING_TYPE IDENTIFIER ASSIGN STRING_LITERAL ';'                       {
        declareVar($2);
        emit("printf %s 0 0", $4);
    }
  | IDENTIFIER ASSIGN expression ';'                                       { emit("mov %s %s 0", regOf($1).c_str(), (*$3).c_str()); }
  | IDENTIFIER '(' ')' ';'                                                 { emit("call %s 0 0", $1); }
  | IDENTIFIER '[' expression ']' ASSIGN expression ';'                    {
        std::string idx = *$3;
        std::string name = std::string($1) + "[" + idx + "]";
        emit("mov %s %s 0", regOf(name).c_str(), (*$6).c_str());
    }
  | IDENTIFIER '(' argument_list ')' ';'                                   {
        for (auto &a : *$3) emit("push %s 0 0", a.c_str());
        emit("call %s 0 0", $1);
        emit("popargs 0 0 0");
    }
  | IF '(' expression ')' matched_stmt ELSE matched_stmt                    {
        std::string cond = *$3;
        std::string Lelse = newLabel();
        std::string Lend  = newLabel();
        emit("jf %s %s 0", cond.c_str(), Lelse.c_str());
        emit("jump %s 0 0", Lend.c_str());
        emit("label %s 0 0", Lelse.c_str());
        emit("label %s 0 0", Lend.c_str());
    }
  | WHILE '(' expression ')' block                                          {
        std::string Lstart = newLabel();
        std::string Lend   = newLabel();
        std::string cond   = *$3;
        emit("label %s 0 0", Lstart.c_str());
        emit("jf %s %s 0", cond.c_str(), Lend.c_str());
        emit("jump %s 0 0", Lstart.c_str());
        emit("label %s 0 0", Lend.c_str());
    }
  | FOR '(' for_init ';' expression ';' for_update ')' block                {
        std::string Lstart = newLabel();
        std::string Lend   = newLabel();
        std::string cond   = *$5;
        emit("label %s 0 0", Lstart.c_str());
        emit("jf %s %s 0", cond.c_str(), Lend.c_str());
        emit("jump %s 0 0", Lstart.c_str());
        emit("label %s 0 0", Lend.c_str());
    }
  | PRINT '(' argument_list ')' ';'                                         {
        for (auto &e : *$3) {
            if (e.size() >= 2 && e.front() == '"' && e.back() == '"')
                emit("printf %s 0 0", e.c_str());
            else
                emit("printv %s 0 0", e.c_str());
        }
    }
  | READ '(' IDENTIFIER ')' ';'                                            {
        emit("read %s 0 0", regOf($3).c_str());
    }
  | RETURN expression ';'                                                   {
        std::string r = *$2;
        emit("mov %ret %s 0", r.c_str());
    }
    ;

unmatched_stmt:
    IF '(' expression ')' statement %prec LOWER_THAN_ELSE                    {
        std::string cond = *$3;
        std::string Lend = newLabel();
        emit("jf %s %s 0", cond.c_str(), Lend.c_str());
        emit("label %s 0 0", Lend.c_str());
    }
  | IF '(' expression ')' matched_stmt ELSE unmatched_stmt                  {
        std::string cond  = *$3;
        std::string Lelse = newLabel();
        std::string Lend  = newLabel();
        emit("jf %s %s 0", cond.c_str(), Lelse.c_str());
        emit("jump %s 0 0", Lend.c_str());
        emit("label %s 0 0", Lelse.c_str());
        emit("label %s 0 0", Lend.c_str());
    }

expression:
    NUMBER                                                                 { $$ = new std::string(std::to_string($1)); }
  | IDENTIFIER                                                           { $$ = new std::string(regOf($1)); }
  | STRING_LITERAL                                                       { $$ = new std::string($1); }
  | '(' expression ')'                                                   { $$ = $2; }
  | IDENTIFIER '[' expression ']'                                        {
        std::string idx = *$3;
        std::string name = std::string($1) + "[" + idx + "]";
        $$ = new std::string(regOf(name));
    }
  | expression PLUS expression                                           {
        std::string tmp = newTemp();
        emit("add %s %s %s", tmp.c_str(), (*$1).c_str(), (*$3).c_str());
        $$ = new std::string(tmp);
    }
  | expression MINUS expression                                          {
        std::string tmp = newTemp();
        emit("sub %s %s %s", tmp.c_str(), (*$1).c_str(), (*$3).c_str());
        $$ = new std::string(tmp);
    }
  | expression TIMES expression                                          {
        std::string tmp = newTemp();
        emit("mult %s %s %s", tmp.c_str(), (*$1).c_str(), (*$3).c_str());
        $$ = new std::string(tmp);
    }
  | expression DIVIDE expression                                         {
        std::string tmp = newTemp();
        emit("div %s %s %s", tmp.c_str(), (*$1).c_str(), (*$3).c_str());
        $$ = new std::string(tmp);
    }
  | expression MOD expression                                            {
        std::string tmp = newTemp();
        emit("mod %s %s %s", tmp.c_str(), (*$1).c_str(), (*$3).c_str());
        $$ = new std::string(tmp);
    }
  | expression '<' expression                                            {
        std::string tmp = newTemp();
        emit("less %s %s %s", tmp.c_str(), (*$1).c_str(), (*$3).c_str());
        $$ = new std::string(tmp);
    }
  | expression '>' expression                                            {
        std::string tmp = newTemp();
        emit("greater %s %s %s", tmp.c_str(), (*$1).c_str(), (*$3).c_str());
        $$ = new std::string(tmp);
    }
  | expression LE expression                                              {
        std::string tmp = newTemp();
        emit("lesseq %s %s %s", tmp.c_str(), (*$1).c_str(), (*$3).c_str());
        $$ = new std::string(tmp);
    }
  | expression GE expression                                              {
        std::string tmp = newTemp();
        emit("greatereq %s %s %s", tmp.c_str(), (*$1).c_str(), (*$3).c_str());
        $$ = new std::string(tmp);
    }
  | expression EQ expression                                              {
        std::string tmp = newTemp();
        emit("equal %s %s %s", tmp.c_str(), (*$1).c_str(), (*$3).c_str());
        $$ = new std::string(tmp);
    }
  | expression NE expression                                              {
        std::string tmp = newTemp();
        emit("diff %s %s %s", tmp.c_str(), (*$1).c_str(), (*$3).c_str());
        $$ = new std::string(tmp);
    }
  | expression AND expression                                             {
        std::string tmp = newTemp();
        emit("and %s %s %s", tmp.c_str(), (*$1).c_str(), (*$3).c_str());
        $$ = new std::string(tmp);
    }
  | expression OR expression                                              {
        std::string tmp = newTemp();
        emit("or %s %s %s", tmp.c_str(), (*$1).c_str(), (*$3).c_str());
        $$ = new std::string(tmp);
    }
  | NOT expression                                                        {
        std::string tmp = newTemp();
        emit("not %s %s 0", tmp.c_str(), (*$2).c_str());
        $$ = new std::string(tmp);
    }
  ;

%%

int yyerror(const char *s){
    fprintf(stderr,"Erro sintatico: %s\n",s);
    return 0;
}
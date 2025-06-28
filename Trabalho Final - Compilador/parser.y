%{
#include <cstdio>
#include <cstdarg>
#include <map>
#include <string>
#include <vector>

extern FILE *out;
extern std::string newTemp();
extern void emit(const char *fmt, ...);

struct InfoVar { bool isArray; int size; };
extern std::map<std::string,InfoVar> symtable;
extern std::string exprResult(const std::string&, int, const std::string&);
extern std::string condText(const std::string&);

int yylex(void);
int yyerror(const char *s);
%}

%code requires {
  #include <string>
  #include <vector>
}

%union {
    int num;
    char *id;
    std::string *str;
    std::vector<std::string> *strlist;
}

%token IF ELSE WHILE FOR INT PRINT READ RETURN MAIN
%token PLUS MINUS TIMES DIVIDE ASSIGN LE GE EQ NE
%token MOD AND OR NOT
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
      expression {
          $$ = new std::vector<std::string>();
          $$->push_back(*$1);
      }
    | argument_list ',' expression {
          $1->push_back(*$3);
          $$ = $1;
      }
    ;

statement:
    INT IDENTIFIER ';' {
        std::string var = $2;
        if (symtable.count(var)) yyerror("Declaracao duplicada");
        symtable[var] = {false, 0};
        emit("DECLARA %s AI", var.c_str());
    }
  | INT IDENTIFIER '[' NUMBER ']' ';' {
        std::string var = $2;
        int N = $4;
        if (symtable.count(var)) yyerror("Declaracao duplicada");
        symtable[var] = {true, N};
        for (int i = 0; i < N; ++i)
            emit("DECLARA %s[%d] AI", var.c_str(), i);
    }
  | INT IDENTIFIER '[' NUMBER ']' ASSIGN '{' expression_list '}' ';' {
        std::string var = $2;
        int N = $4;
        auto elems = $8;          
        if (symtable.count(var)) yyerror("Declaracao duplicada");
        symtable[var] = {true, N};
        int idx = 0;
        for (auto &e : *elems) {
          emit("%s[%d] RECEBA %s AI", var.c_str(), idx++, e.c_str());
        }
    }
  | STRING_TYPE IDENTIFIER ';' {
        std::string var = $2;
        if (symtable.count(var)) yyerror("Declaracao duplicada");
        symtable[var] = {false, 0};
    }
  | STRING_TYPE IDENTIFIER ASSIGN STRING_LITERAL ';' {
        std::string var = $2;
        std::string lit = $4;
        if (symtable.count(var)) yyerror("Declaracao duplicada");
        symtable[var] = {false, 0};
        emit("DCLSTR %s %s", var.c_str(), lit.c_str());
    }
  | IDENTIFIER ASSIGN expression ';' {
        std::string dest = $1;
        std::string src  = *$3;
        emit("%s RECEBA %s AI", dest.c_str(), src.c_str());
    }
  | IDENTIFIER '(' ')' ';' {
        emit("CHAMA %s", $1);
    }
  | IDENTIFIER '[' expression ']' ASSIGN expression ';' {
        std::string var = $1;
        std::string idx = *$3;
        std::string val = *$6;
        emit("%s[%s] RECEBA %s AI", var.c_str(), idx.c_str(), val.c_str());
    }
  | IDENTIFIER '(' argument_list ')' ';' {
        auto args = $3;          /* vector<Node*>* */
        for (size_t i = 0; i < args->size(); ++i) {
          emit("PUSH %s", (*args)[i].c_str());
        }
        emit("CHAMA %s", $1);
        emit("LIMPAARGS");
    }
  | IF '(' expression ')' block {
        std::string cond = condText(*$3);
        emit("SERAQUE %s ? SEFOR (", cond.c_str());
        emit(")");
    }
  | IF '(' expression ')' block ELSE block {
        std::string cond = condText(*$3);
        emit("SERAQUE %s ? SEFOR (", cond.c_str());
        emit(") SEINAO (");
        emit(")");
    }
  | FOR '(' for_init ';' expression ';' for_update ')' block {
      std::string cond = condText(*$5); 
      emit("ENQUANTO %s ? FACA (", cond.c_str());
      emit(")");
  }
  | WHILE '(' expression ')' block {
        std::string cond = condText(*$3);
        emit("ENQUANTO %s ? FACA (", cond.c_str());
        emit(")");
    }
  | PRINT '(' argument_list ')' ';' {
        std::string seq;
        for (size_t i = 0; i < $3->size(); ++i) {
            if (i > 0) seq += " DEPOIS ";
            seq += (*$3)[i];
        }
        emit("MOSTRA %s AI", seq.c_str());
    }
  | READ '(' argument_list ')' ';' {
        for (size_t i = 0; i < $3->size(); ++i) {
            emit("MEDAH %s AI", (*$3)[i].c_str());
        }
    }
  | RETURN expression ';' {
        std::string ret = *$2;
        emit("RETORNA %s AI", ret.c_str());
    }
  ;

expression_list:
      expression {
          $$ = new std::vector<std::string>();
          $$->push_back(*$1);
      }
    | expression_list ',' expression {
          $1->push_back(*$3);
          $$ = $1;
      }
    ;

expression:
    NUMBER {
        $$ = new std::string(std::to_string($1));
    }
  | IDENTIFIER {
        $$ = new std::string($1);
    }
  | STRING_LITERAL {
        $$ = new std::string($1);
    }
  | '(' expression ')' {
        $$ = $2;
    }
  | expression PLUS  expression {
        std::string tmp = exprResult(*$1, PLUS,  *$3);
        $$ = new std::string(tmp);
    }
  | expression MINUS expression {
        std::string tmp = exprResult(*$1, MINUS, *$3);
        $$ = new std::string(tmp);
    }
  | expression TIMES expression {
        std::string tmp = exprResult(*$1, TIMES, *$3);
        $$ = new std::string(tmp);
    }
  | expression DIVIDE expression {
        std::string tmp = exprResult(*$1, DIVIDE, *$3);
        $$ = new std::string(tmp);
    }
  | expression MOD    expression {
        std::string tmp = exprResult(*$1, MOD, *$3);
        $$ = new std::string(tmp);
    }
  | expression LE     expression {
        std::string tmp = exprResult(*$1, LE, *$3);
        $$ = new std::string(tmp);
    }
  | expression GE     expression {
        std::string tmp = exprResult(*$1, GE, *$3);
        $$ = new std::string(tmp);
    }
  | expression EQ     expression {
        std::string tmp = exprResult(*$1, EQ, *$3);
        $$ = new std::string(tmp);
    }
  | expression NE     expression {
        std::string tmp = exprResult(*$1, NE, *$3);
        $$ = new std::string(tmp);
    }
  | expression '<'    expression {
        std::string tmp = exprResult(*$1, '<', *$3);
        $$ = new std::string(tmp);
    }
  | expression '>'    expression {
        std::string tmp = exprResult(*$1, '>', *$3);
        $$ = new std::string(tmp);
    }
  | expression AND    expression {
        std::string tmp = exprResult(*$1, AND, *$3);
        $$ = new std::string(tmp);
    }
  | expression OR     expression {
        std::string tmp = exprResult(*$1, OR, *$3);
        $$ = new std::string(tmp);
    }
  | NOT expression {
        std::string tmp = exprResult("", NOT, *$2);
        $$ = new std::string(tmp);
    }
  ;

%%

int yyerror(const char *s) {
    fprintf(stderr, "Erro sintático: %s\n", s);
    return 0;
}

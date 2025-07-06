%{
#include <stdio.h>
#include <string.h>
extern FILE *yyout;
#define emit(fmt, ...) fprintf(yyout, fmt, __VA_ARGS__)
typedef struct {
    char *id;
    int end;
} simb;

typedef struct {
    char *id;
    int tmp1;
    int tmp2;
    int tmp3;
} expr;

expr tab[1000];
simb tabsimb[10000];
int expressao[200];
int stack[200];
int doelse[100];

int numsimbs = 0;
int adress = 0;
int headtabela = 0;
int vazio = -1;
int head = 0;
int headexpressao = 0;
int jf_count = 0;
int T = 0;
int rot = 0;
int felse = 0;

int pop(void) {
    head--;
    if(head < 0) {
      return 0;
    }
    else {
      return stack[head];
    }
}

void pop_tab(int tmp1) {
    printf("%s %%t%d, %%t%d, %%t%d \n", tab[headtabela].id, tmp1+1, tab[headtabela].id, tmp1+1, tab[headtabela].tmp2,tmp1); 
}

void push(int x)
{
	if(head >= 200) {
	   printf("Erro, Stack cheia. \n");
	   return 0;
	}
	stack[head] = x;
	head++;
}

int getadress(char *id) { 
	for (int i=0;i<numsimbs;i++)
	    if(!strcmp(tabsimb[i].id,id))
	    	return tabsimb[i].end;
	return -1;
}

int pop_expressao(void) 
{
  headexpressao--;
  if(expressao < 0)
  {
  	return 0;
  }
  
  return expressao[headexpressao];
}

void push_expressao(int x)
{
	if(headexpressao >= 200) {
	   printf("stack cheia \n");
	   return 0;
	}
	expressao[headexpressao] = x;
	headexpressao++;
}

%} 

%union {
    char *str_val;
    int int_val;    
}

%token <str_val> ID ATRIB PEV VETOR FOR WHILE IF ELSE INT PRINTF STRING SCANF COMENT ERRO COMENTARIO 
%token <int_val> NUM MAISMAIS MENOR IGUAL MAIOR DIFERENTE MAIORIGUAL MENORIGUAL MENOSMENOS
%token  LPAR RPAR LCHAVE RCHAVE LCOL RCOL MAIS MENOS MULT DIVINT MOD DIV APOST AND OR BREAK

%type <int_val> expr termo expr2 express
%type <str_val> count for for_loop for_ins operacao jv 

%define parse.error verbose

%%

code: 
    atrib code 
    | for_loop code 
    | while_loop code 
    | show code 
    | check code 
    | receive code 
    | BREAK PEV { printf("jump R0%d\n", stack[head - 1]); }
    | ERRO  
    | ;

show: 
    PRINTF LPAR printf RPAR PEV ;

printf: 
    expr {printf("printv %%t%d \n",$1);} COMENT printf
    | STRING {printf("printf %s\n",$1);} COMENT printf 
    | expr {printf("printv %%t%d \n",$1);}
    | STRING {printf("printf %s\n",$1);};

receive: 
    SCANF LPAR ID RPAR {int end = getadress($3);printf("read %%r%d\n",end);} PEV 
    | SCANF LPAR ID LCOL expr {int end = getadress($3);printf("read %%t%d\nstore %%t%d, %%t%d(%d)\n", T, T,$5,end);T++;} RCOL RPAR PEV;     

atrib: 
    INT ID ATRIB expr PEV {printf("mov %%r%d, %%t%d\n", getadress($2), $4);} 
    | INT ID PEV {tabsimb[numsimbs] = (simb){$2, adress}; numsimbs++;adress++;}
    | ID ATRIB expr PEV {printf("mov %%r%d, %%t%d\n", getadress($1), $3);} 
    | INT ID LCOL NUM {tabsimb[numsimbs] = (simb){$2, adress}; numsimbs++;adress = $4 ;} RCOL PEV 
    | ID LCOL expr RCOL ATRIB expr {int x = getadress($1);printf("store %%t%d, %%t%d(%d)\n",T-1,$3,x);} PEV;

express: 
    expr operacao expr jv {printf("%s %%t%d, %%t%d, %%t%d\n", $2 ,T, $1, $3);tab[headtabela].tmp2 = T;T++;tab[headtabela].id = $4;vazio=0;} express  
    | expr operacao expr {printf("%s %%t%d, %%t%d, %%t%d\n", $2 ,T, $1, $3);push_expressao(T);if(vazio!=-1){pop_tab(T);T++;};vazio!=-1;} 
    | LPAR express RPAR jv express {printf("%s %%t%d, %%t%d, %%t%d \n",$4,T,pop_expressao(),pop_expressao());$$ = $2;}
    | LPAR express RPAR {$$ = $2;};

expr: 
    expr MAIS expr2 {printf("add %%t%d, %%t%d, %%t%d\n", T, $1, $3); $$ = T++;}
    | expr MENOS expr2 {printf("sub %%t%d, %%t%d, %%t%d\n", T, $1, $3); $$ = T++;} 
    | expr2 {$$ = $1;};
      
expr2: 
    expr2 DIV termo {printf("div %%t%d, %%t%d, %%t%d\n", T, $1, $3); $$ = T++;}
    | expr2 MULT termo {printf("mult %%t%d, %%t%d, %%t%d\n", T, $1, $3); $$ = T++;}
    | expr2 MOD termo  {printf("mod %%t%d, %%t%d, %%t%d\n", T, $1, $3); $$ = T++;}
    | termo {$$ = $1;};

operacao: 
    MAIOR {$$ = "greater";}	     
    | MENOR {$$ = "less";}
    | IGUAL {$$ = "equal";}
    | DIFERENTE {$$ = "diff";}
    | MENORIGUAL {$$ = "lesseq";}
    | MAIORIGUAL {$$ = "greatereq";};

termo: 
    ID { int end = getadress($1); printf("mov %%t%d, %%r%d\n", T, end); $$ = T++;}
    | NUM  { printf("mov %%t%d, %d\n", T, $1); $$ = T++; }
    | LPAR expr RPAR { $$ = $2; }
    | MENOS ID  { int end = getadress($2); printf("mov %%t%d, %%r%d\n", T, end); $$ = T++;} 
    | MENOS NUM { printf("mov %%t%d, %d\n", T, $2); $$ = T++; }
    | ID LCOL expr RCOL { int end = getadress($1);printf("load %%t%d, %%t%d(%d) \n",T,$3,end); $$ = T++;} ;

for: 
    ID operacao expr {int end = getadress($1); printf("%s %%t%d, %%r%d, %%t%d\njf %%t%d, R0%d\n",$2,T,end,$3, T, jf_count);$$=$1;T++;};

for_loop:
    FOR LPAR atrib {jf_count = rot+1;printf("label R0%d\n",rot); push(rot++); push(rot++);} for PEV for_ins   RPAR LCHAVE code RCHAVE {int end = getadress($5);printf("add %%r%d, %%r%d, 1\n",end,end); printf("jump R0%d\nlabel R0%d\n",pop(),pop());}; 

for_ins: 
    count ID {$$ = $2;}
    | ID count {$$ = $1;};

check: 
    IF  { jf_count=rot;push(rot++); push(rot++);} LPAR express {printf("jf %%t%d, R0%d\n",T, jf_count);T++;}RPAR LCHAVE code RCHAVE else ;

else: 
    ELSE {doelse[felse++]=pop();printf("jump R0%d\n",doelse[felse-1]);printf("label R0%d\n",pop());} LCHAVE code RCHAVE {printf("label R0%d\n",doelse[--felse]); }	
    | { int x = pop();printf("jump R0%d\n",x);printf("label R0%d\nlabel R0%d\n",pop(),x);};

while_loop: 
    WHILE {jf_count = rot+1;printf("label R0%d \n",rot); push(rot++); push(rot++);} LPAR express {printf("jf %%t%d, R0%d\n",T,jf_count);T++;}RPAR LCHAVE code { } RCHAVE {printf("jump R0%d\nlabel R0%d\n",pop(),pop());};

count:
    MAISMAIS {$$ = "add";}
    | MENOSMENOS {$$ = "sub";};

jv:
    AND {$$ = "and";}
    | OR {$$ = "or";};

%%

extern FILE *yyin;                   

void yyerror(char *s) { fprintf(stderr,"Erro Sintatico Encontrado : %s\n", s) ;}
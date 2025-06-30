%{
#include <stdio.h>
#include <string.h>
extern FILE *yyout;
#define emit(fmt, ...) fprintf(yyout, fmt, __VA_ARGS__)
typedef struct {
    char *id;
    int end;
} simbolo;

typedef struct {
    char *id;
    int t1;
    int t2;
    int t3;
} expressao;

expressao tabela[1000];
simbolo tabsimb[10000];
int nsimbs = 0;
int endereco = 0;
int topo_tabela = 0;

// Vazio verifica se a expressão de comparação tem ou não tem AND ou OR 

int vazio = -1;

int pilha[200];
int topo = 0;

// Mesma linha de raciocino para as expressões com parenteses

int expre[200];
int topo_expre = 0;

// contagem_jf é a variavel para mostrar os numeros de jf

int contagem_jf = 0;
int T = 0;
int rotulo = 0;

// Esse vetor armazenar os pop's() do else para mostrar no final

int finalDoElse[100];
int fina_else = 0;

// Mostra o AND ou OR e a expressão que está com ele

void pop_tabela(int t1)
{
 
 printf("%s %%t%d, %%t%d, %%t%d \n",tabela[topo_tabela].id,t1+1,tabela[topo_tabela].t2,t1);

}


int getendereco(char *id) { 
	for (int i=0;i<nsimbs;i++)
	    if(!strcmp(tabsimb[i].id,id))
	    	return tabsimb[i].end;
	return -1;
}

// Armazena as variaveis para as expressoes com parenteses

void push_expre(int x)
{
	if(topo_expre >= 200) {
	   printf("Pilha cheia \n");
	   return 0;
	}
	expre[topo_expre] = x;
	topo_expre++;
}

// Mostra a variavel

int pop_expre(void) 
{
  topo_expre--;
  if(expre < 0)
  {
  	return 0;
  }
  
  return expre[topo_expre];
}

// Essa a pilha utilizada para os numeros utilizados dos FOR, WHILE e IF

void push(int x)
{
	if(topo >= 200) {
	   printf("Pilha cheia \n");
	   return 0;
	}
	pilha[topo] = x;
	topo++;
}

int pop(void) 
{
  topo--;
  if(topo < 0)
  {
  	return 0;
  }
  return pilha[topo];
}

%}

%union {
    char *str_val;
    int int_val;    
}

// tokens do código


%token <str_val> ID ATRIB PEV VETOR FOR WHILE IF ELSE INT PRINTF STRING SCANF COMENT ERRO COMENTARIO 
%token <int_val> NUM MAISMAIS MENOR IGUAL MAIOR DIFERENTE MAIORIGUAL MENORIGUAL MENOSMENOS
%token  LPAR RPAR LCHAVE RCHAVE LCOL RCOL MAIS MENOS MULT DIVINT MOD DIV APOST AND OR BREAK

%type <int_val> expr termo expr2 expressoes
%type <str_val> operacao jv contagem for lacofor dentrofor

%define parse.error verbose

%%

// gramática para conseguir ler várias linhas do arquivo

linhaDeCodigo : atrib linhaDeCodigo 
              | lacofor linhaDeCodigo 
              | lacowhile linhaDeCodigo 
              | mostrar linhaDeCodigo 
              | se linhaDeCodigo 
              | receber linhaDeCodigo 
              | BREAK PEV { printf("jump R0%d\n", pilha[topo - 1]); }
              | ERRO  
              | ;	          
                          
// Armazena valores para variaveis e vetores        
        
receber : SCANF LPAR ID RPAR {int end = getendereco($3);printf("read %%r%d\n",end);} PEV 
        | SCANF LPAR ID LCOL expr {int end = getendereco($3);printf("read %%t%d\nstore %%t%d, %%t%d(%d)\n", T, T,$5,end);T++;} RCOL RPAR PEV;          
             
mostrar : PRINTF LPAR printf RPAR PEV ;

// Mostra string e variaveis na tela

printf : expr {printf("printv %%t%d \n",$1);} COMENT printf
       | STRING {printf("printf %s\n",$1);} COMENT printf 
       | expr {printf("printv %%t%d \n",$1);}
       | STRING {printf("printf %s\n",$1);};

// atribuicoes e declaracoes de varaiveis
// variavel endereco serve como auxiliar para salvar a posicao das variaveis depois de uma declaracao do vetor        
      
atrib : INT ID ATRIB expr PEV {printf("mov %%r%d, %%t%d\n", getendereco($2), $4);} 
      | INT ID PEV {tabsimb[nsimbs] = (simbolo){$2, endereco}; nsimbs++;endereco++;}
      | ID ATRIB expr PEV {printf("mov %%r%d, %%t%d\n", getendereco($1), $3);} 
      | INT ID LCOL NUM {tabsimb[nsimbs] = (simbolo){$2, endereco}; nsimbs++;endereco = $4 ;} RCOL PEV 
      | ID LCOL expr RCOL ATRIB expr {int x = getendereco($1);printf("store %%t%d, %%t%d(%d)\n",T-1,$3,x);} PEV;	

// regra principal do for 

lacofor : FOR LPAR atrib {contagem_jf = rotulo+1;printf("label R0%d\n",rotulo); push(rotulo++); push(rotulo++);} for PEV dentrofor RPAR LCHAVE linhaDeCodigo RCHAVE {int end = getendereco($5);printf("add %%r%d, %%r%d, 1\n",end,end); printf("jump R0%d\nlabel R0%d\n",pop(),pop());}; 

// regra para depois do ; para rodar no for

for : ID operacao expr {int end = getendereco($1); printf("%s %%t%d, %%r%d, %%t%d\njf %%t%d, R0%d\n",$2,T,end,$3, T, contagem_jf);$$=$1;T++;};

// utilizada por seguir um padrão na declaração do for

dentrofor : contagem ID {$$ = $2;}
          | ID contagem {$$ = $1;};        
        
// Regra do While         
        
lacowhile : WHILE {contagem_jf = rotulo+1;printf("label R0%d \n",rotulo); push(rotulo++); push(rotulo++);} LPAR expressoes {printf("jf %%t%d, R0%d\n",T,contagem_jf);T++;}RPAR LCHAVE linhaDeCodigo { } RCHAVE {printf("jump R0%d\nlabel R0%d\n",pop(),pop());};

// Regra do if

se : IF  { contagem_jf=rotulo;push(rotulo++); push(rotulo++);} LPAR expressoes {printf("jf %%t%d, R0%d\n",T, contagem_jf);T++;}RPAR LCHAVE linhaDeCodigo RCHAVE else ;

// Para o else utilizamos variaveis auxiliar para salvar o primeiro pop e mostrar no final do else

else : ELSE {finalDoElse[fina_else++]=pop();printf("jump R0%d\n",finalDoElse[fina_else-1]);printf("label R0%d\n",pop());} LCHAVE linhaDeCodigo RCHAVE {printf("label R0%d\n",finalDoElse[--fina_else]); }	
     | { int x = pop();printf("jump R0%d\n",x);printf("label R0%d\nlabel R0%d\n",pop(),x);};

// A regra expressoes foi utilizado de forma semalhante as variaveis auxiliares de forma que apenas depois da ultima expressao de comparação mostra - se o AND ou o OR  

expressoes : expr operacao expr jv {printf("%s %%t%d, %%t%d, %%t%d\n", $2 ,T, $1, $3);tabela[topo_tabela].t2 = T;T++;tabela[topo_tabela].id = $4;vazio=0;} expressoes  
           | expr operacao expr {printf("%s %%t%d, %%t%d, %%t%d\n", $2 ,T, $1, $3);push_expre(T);if(vazio!=-1){pop_tabela(T);T++;};vazio!=-1;} 
           | LPAR expressoes RPAR jv expressoes {printf("%s %%t%d, %%t%d, %%t%d \n",$4,T,pop_expre(),pop_expre());$$ = $2;}
           | LPAR expressoes RPAR {$$ = $2;};
           
// Retorna qual é a operacao de comparação           

operacao : MAIOR {$$ = "greater";}	     
         | MENOR {$$ = "less";}
         | IGUAL {$$ = "equal";}
         | DIFERENTE {$$ = "diff";}
         | MENORIGUAL {$$ = "lesseq";}
         | MAIORIGUAL {$$ = "greatereq";}; 

// Retorna qual se é AND ou OR

jv : AND {$$ = "and";}
   | OR {$$ = "or";};
          
// Outra regra não implementada

contagem : MAISMAIS {$$ = "add";}
         | MENOSMENOS {$$ = "sub";};

// Mostra as operações aritimeticas na ordem

expr : expr MAIS expr2 {printf("add %%t%d, %%t%d, %%t%d\n", T, $1, $3); $$ = T++;}
     | expr MENOS expr2 {printf("sub %%t%d, %%t%d, %%t%d\n", T, $1, $3); $$ = T++;} 
     | expr2 {$$ = $1;};
      
expr2 : expr2 DIV termo {printf("div %%t%d, %%t%d, %%t%d\n", T, $1, $3); $$ = T++;}
      | expr2 MULT termo {printf("mult %%t%d, %%t%d, %%t%d\n", T, $1, $3); $$ = T++;}
      | expr2 MOD termo  {printf("mod %%t%d, %%t%d, %%t%d\n", T, $1, $3); $$ = T++;}
      | termo {$$ = $1;};
     
// Os termos são o que pode ser no final de cada expr     
     
termo : ID { int end = getendereco($1); printf("mov %%t%d, %%r%d\n", T, end); $$ = T++;}
      | NUM  { printf("mov %%t%d, %d\n", T, $1); $$ = T++; }
      | LPAR expr RPAR { $$ = $2; }
      | MENOS ID  { int end = getendereco($2); printf("mov %%t%d, %%r%d\n", T, end); $$ = T++;} 
      | MENOS NUM { printf("mov %%t%d, %d\n", T, $2); $$ = T++; }
      | ID LCOL expr RCOL { int end = getendereco($1);printf("load %%t%d, %%t%d(%d) \n",T,$3,end); $$ = T++;} ;

%%

extern FILE *yyin;                   

void yyerror(char *s) { fprintf(stderr,"ERRO SINTATICO : %s\n", s) ;}
# Makefile

# Alvo principal
all: analisador

# Gera parser.tab.c e parser.tab.h a partir de parser.y
parser.tab.c parser.tab.h: parser.y
	bison -d parser.y

# Gera lex.yy.c a partir de lexer.l, mas só depois que parser.tab.h existir
lex.yy.c: lexer.l parser.tab.h
	flex lexer.l

# Compila tudo
analisador: parser.tab.c lex.yy.c main.c
	gcc -o analisador main.c parser.tab.c lex.yy.c -lfl

clean:
	rm -f analisador parser.tab.* lex.yy.c

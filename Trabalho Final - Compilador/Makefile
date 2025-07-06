# Makefile

# Ferramentas
BISON      := bison
BISONFLAGS := --warnings=none
FLEX       := flex
CC         := gcc

# Suprime *todos* os warnings do GCC
CFLAGS     := -w

# Link com flex
LDFLAGS    := -lfl

.PHONY: all clean

all: analisador

parser.tab.c parser.tab.h: parser.y
	$(BISON) $(BISONFLAGS) -d $<

lex.yy.c: lexer.l parser.tab.h
	$(FLEX) $<

analisador: main.c parser.tab.c lex.yy.c
	$(CC) $(CFLAGS) -o $@ main.c parser.tab.c lex.yy.c $(LDFLAGS)

clean:
	rm -f analisador parser.tab.* lex.yy.c

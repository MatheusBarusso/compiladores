#include <stdio.h>

extern FILE *yyin;
int yyparse(void);

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <arquivo-de-entrada>\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("fopen");
        return 1;
    }

    if (yyparse() == 0) {
        // parsing OK
    }

    fclose(yyin);
    return 0;
}

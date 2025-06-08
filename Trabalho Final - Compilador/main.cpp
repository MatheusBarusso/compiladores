#include <iostream>

extern int yyparse(); // função gerada pelo Bison
extern void yyrestart(FILE*); // função gerada pelo Flex para reiniciar o scanner

int main(int argc, char** argv) {
    std::cout << "Iniciando analisador ++C..." << std::endl;

    if (argc > 1) {
        FILE* file = fopen(argv[1], "r");
        if (!file) {
            std::cerr << "Erro ao abrir o arquivo: " << argv[1] << std::endl;
            return 1;
        }
        yyrestart(file);
    }

    if (yyparse() == 0) {
        std::cout << "Análise concluída com sucesso, programa segue as normas sintéticas e léxicas" << std::endl;
    } else {
        std::cerr << "Falha na análise." << std::endl;
    }

    return 0;
}
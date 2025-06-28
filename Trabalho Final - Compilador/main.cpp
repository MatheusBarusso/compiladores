// main.cpp

#include <cstdio>
#include <cstdarg>
#include <map>
#include <string>
#include "parser.tab.h"

extern FILE *yyin;
extern int yyparse();

FILE *out;                          // agora global, não static
int tempCount = 0;                  // contador de temporários, global
struct InfoVar { bool isArray; int size; };
std::map<std::string,InfoVar> symtable;  // definição de symtable

std::string newTemp() {
    return "_t" + std::to_string(++tempCount);
}

void emit(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(out, fmt, args);
    fputc('\n', out);
    va_end(args);
}

// Exemplo simplificado de exprResult:
// - left  é "" quando for NOT uniário
// - op    é um dos PLUS, MINUS, TIMES, DIVIDE, MOD, LE, GE, EQ, NE, '<', '>', AND, OR, NOT
// - right é o operando direito (ou o único, no caso de NOT)
std::string exprResult(const std::string &left, int op, const std::string &right) {
    // Gere um temporário para resultado
    std::string tmp = newTemp();
    // Dependendo de op, mude o texto
    const char *opText;
    switch(op) {
      case PLUS:    opText = "SOMADO COM"; break;
      case MINUS:   opText = "MENOS";      break;
      case TIMES:   opText = "VEZES";      break;
      case DIVIDE:  opText = "DIVIDIDO POR"; break;
      case MOD:     opText = "RESTO";      break;
      case LE:      opText = "EHMENOROUIGUAL"; break;
      case GE:      opText = "EHMAIOROUIGUAL"; break;
      case EQ:      opText = "EHIGUAL";      break;
      case NE:      opText = "EHDIFERENTE";  break;
      case '<':     opText = "EHMENORQUE";   break;
      case '>':     opText = "EHMAIORQUE";   break;
      case AND:     opText = "E";            break;
      case OR:      opText = "OU";           break;
      case NOT:
        emit("NAO %s AI", right.c_str());
        return right;
        default:
        opText = "??"; 
    }
    if (left.empty()) {
        // (caso especial, mas geralmente não usado)
        emit("%s RECEBA %s AI", tmp.c_str(), right.c_str());
    } else {
        emit("%s RECEBA %s %s %s AI",
             tmp.c_str(),
             left.c_str(),
             opText,
             right.c_str());
    }
    return tmp;
}

// Gera o texto da condição a ser colocado em SERAQUE/ENQUANTO
std::string condText(const std::string &s) {
    return s;  // assumindo que exprResult já gerou algo como "a EHMAIORQUE b"
}

int main(int argc, char **argv) {
    if (argc < 2) { fprintf(stderr,"Uso: %s <fonte>\n",argv[0]); return 1; }
    yyin = fopen(argv[1], "r");
    if (!yyin) { perror("fopen"); return 1; }
    out = fopen("saida.rps","w");
    if (!out) { perror("fopen saida"); return 1; }
    if (yyparse() == 0) {
        printf("Compilação OK, veja saida.rps\n");
    }
    fclose(yyin);
    fclose(out);
    return 0;
}

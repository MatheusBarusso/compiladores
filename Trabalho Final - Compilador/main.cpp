// main.cpp

#include <cstdio>
#include <cstdarg>
#include <map>
#include <string>
#include <vector>
#include "parser.tab.h"

FILE *out;
extern FILE *yyin;
int tempCount = 0;
int nextReg   = 0;
int nextLabel = 0;
std::map<std::string,int> varMap;

std::string newTemp() {
    return "%t" + std::to_string(++tempCount);
}

std::string newLabel() {
    return "L" + std::to_string(++nextLabel);
}

std::string regOf(const std::string &name) {
    auto it = varMap.find(name);
    if (it == varMap.end()) {
        varMap[name] = nextReg++;
        it = varMap.find(name);
    }
    return "%r" + std::to_string(it->second);
}

void declareVar(const std::string &name) {
    if (varMap.find(name) == varMap.end()) {
        varMap[name] = nextReg++;
    }
}

void declareArray(const std::string &name, int size) {
    for (int i = 0; i < size; ++i) {
        std::string elem = name + "[" + std::to_string(i) + "]";
        if (varMap.find(elem) == varMap.end()) {
            varMap[elem] = nextReg++;
        }
    }
}

void emit(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(out, fmt, args);
    fputc('\n', out);
    va_end(args);
}

std::string exprResult(const std::string &left, int op, const std::string &right) {
    std::string tmp = newTemp();
    switch (op) {
      case PLUS:    emit("add %s %s %s", tmp.c_str(), left.c_str(), right.c_str()); break;
      case MINUS:   emit("sub %s %s %s", tmp.c_str(), left.c_str(), right.c_str()); break;
      case TIMES:   emit("mult %s %s %s", tmp.c_str(), left.c_str(), right.c_str()); break;
      case DIVIDE:  emit("div %s %s %s", tmp.c_str(), left.c_str(), right.c_str()); break;
      case MOD:     emit("mod %s %s %s", tmp.c_str(), left.c_str(), right.c_str()); break;
      case '<':     emit("less %s %s %s", tmp.c_str(), left.c_str(), right.c_str()); break;
      case '>':     emit("greater %s %s %s", tmp.c_str(), left.c_str(), right.c_str()); break;
      case LE:      emit("lesseq %s %s %s", tmp.c_str(), left.c_str(), right.c_str()); break;
      case GE:      emit("greatereq %s %s %s", tmp.c_str(), left.c_str(), right.c_str()); break;
      case EQ:      emit("equal %s %s %s", tmp.c_str(), left.c_str(), right.c_str()); break;
      case NE:      emit("diff %s %s %s", tmp.c_str(), left.c_str(), right.c_str()); break;
      case AND:     emit("and %s %s %s", tmp.c_str(), left.c_str(), right.c_str()); break;
      case OR:      emit("or %s %s %s", tmp.c_str(), left.c_str(), right.c_str()); break;
      case NOT:     emit("not %s %s 0", tmp.c_str(), right.c_str()); break;
      default:      break;
    }
    return tmp;
}

std::string condText(const std::string &s) {
    return s;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <arquivo>\n", argv[0]);
        return 1;
    }
    yyin = fopen(argv[1], "r");
    if (!yyin) { perror("fopen"); return 1; }
    out = fopen("saida.rps", "w");
    if (!out) { perror("fopen saida"); return 1; }
    if (yyparse() == 0) {
        printf("Compilação bem-sucedida. Código em saida.rps\n");
    }
    fclose(yyin);
    fclose(out);
    return 0;
}

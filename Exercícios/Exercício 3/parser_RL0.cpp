#include <iostream>
#include <string>
#include <stack>
#include <locale.h>

using namespace std;

string entrada;
int pos = 0;

bool parser() {
    stack<char> pilha;
    while (pos < entrada.size()) {
        char simbolo = entrada[pos];

        if (simbolo == 'n') {
            pilha.push('E'); // Reduz imediatamente n → E
        }
        else if (simbolo == '+') {
            // Para reduzir E E + → E, precisamos de topo: E E
            if (pilha.size() < 2) return false;

            char topo1 = pilha.top(); pilha.pop();
            char topo2 = pilha.top(); pilha.pop();

            if (topo1 == 'E' && topo2 == 'E') {
                pilha.push('E'); // E E + → E
            } else {
                return false;
            }
        } else {
            return false; // caractere inválido
        }

        pos++;
    }

    // Ao final, a pilha deve conter apenas um E
    return pilha.size() == 1 && pilha.top() == 'E';
}

int main() {
    setlocale(LC_ALL, "");
    cin >> entrada;
    pos = 0;

    if (parser()) {
        cout << "entrada valida" << endl;
    } else {
        cout << "erro sintatico" << endl;
    }

    return 0;
}

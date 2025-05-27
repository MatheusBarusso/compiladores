#include <iostream>
#include <string>
#include <locale.h>

using namespace std;

string entrada;
int pos = 0;

char atual() {
    if (pos < entrada.length()) {
        return entrada[pos];
    }
    return '\0';
}

bool consumir(char c) {
    if (atual() == c) {
        pos++;
        return true;
    }
    return false;
}

bool L();
bool D();
bool D_();
bool E();
bool E_();
bool A();

// L → i | n i | (E) | n(E)
bool L() {
    if (consumir('i')) {
        return true;
    }
    else if (consumir('n')) {
        if (consumir('i')) {
            return true;
        }
        else if (consumir('(')) {
            if (E() && consumir(')')) {
                return true;
            }
        }
    }
    else if (consumir('(')) {
        if (E() && consumir(')')) {
            return true;
        }
    }
    return false;
}

// D → L D'
bool D() {
    if (L()) {
        return D_();
    }
    return false;
}

// D' → o L D' | ε
bool D_() {
    if (consumir('o')) {
        if (L()) {
            return D_();
        }
        return false;
    }
    return true;
}

// E → D E'
bool E() {
    if (D()) {
        return E_();
    }
    return false;
}

// E' → e D E' | ε
bool E_() {
    if (consumir('e')) {
        if (D()) {
            return E_();
        }
        return false;
    }
    return true;
}

// A → i = E
bool A() {
    if (consumir('i')) {
        if (consumir('=')) {
            return E();
        }
    }
    return false;
}

int main() {
    setlocale(LC_ALL, "");
    cin >> entrada;
    pos = 0;

    if (A() && pos == entrada.length()) {
        cout << "entrada valida" << endl;
    } else {
        cout << "erro sintatico" << endl;
    }

    return 0;
}

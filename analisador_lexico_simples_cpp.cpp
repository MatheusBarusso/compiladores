#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <locale.h>

using namespace std;

enum class TipoDeToken {
    PalavraImp,
    Variavel,
    Numero,
    Operador,
    Delimitador,
    LiteralChar,
    Desconhecido
};

struct Token {
    TipoDeToken tipo;
    string texto;
    Token(TipoDeToken t, const string& l) : tipo(t), texto(l) {}
};

bool checaPalavraImp(const string& str) {
    static const vector<string> PalavrasImp = {"int", "char", "string", "for", "if", "else"};
    return find(PalavrasImp.begin(), PalavrasImp.end(), str) != PalavrasImp.end();
}

bool checaVariavel(const string& str) {

    if (!isalpha(str[0]) && str[0] !='_') {
        return false;
    }
    for (char h : str) {
        if(!isalnum(h) && h !='_') {
            return false;
        }
    }
    return !checaPalavraImp(str);
}

bool checaNumero(const string& str) {
    size_t pos;
    try {
        std::stod(str, &pos);
        return pos == str.length();
    }
    catch (...) {
        return false;
    }
}

bool checaOperador(const string& str) {
    static const vector<string> operadores = {"+", "++", "-", "*", "/", "=", "==", "!=", "<", ">", "%"};
    return find(operadores.begin(), operadores.end(), str) != operadores.end();
}

bool checaDelimitador(const string& str) {
    static const vector<string> delimitadores = {";", "(", ")", "{", "}"};
    return find(delimitadores.begin(), delimitadores.end(), str) != delimitadores.end();
}

bool checaLiteralChar(const string& str) {
    return str.length() == 3 && str[0] == '\'' && str[2] == '\'';
}

Token classificaPalavra(const string& palavra) {
    if(checaPalavraImp(palavra)) {
        return Token(TipoDeToken::PalavraImp, palavra);
    }
    else if(checaVariavel(palavra)) {
        return Token(TipoDeToken::Variavel, palavra);
    }
    else if(checaNumero(palavra)) {
        return Token(TipoDeToken::Numero, palavra);
    }
    else if(checaOperador(palavra)) {
        return Token(TipoDeToken::Operador, palavra);
    }
    else if(checaDelimitador(palavra)) {
        return Token(TipoDeToken::Delimitador, palavra);
    }
    else if(checaLiteralChar(palavra)) {
        return Token(TipoDeToken::LiteralChar, palavra);
    }
    else {
    return Token(TipoDeToken::Desconhecido, palavra);
    }
}

vector<string> extraiTokens(const string& linha) {
    vector<string> tokens;
    string buffer;

    for(char c : linha) {
        if(isspace(c)) {
            if(!buffer.empty()) {
                tokens.push_back(buffer);
                buffer.clear();
            }
        }
        else if(string("(){};").find(c) != string::npos) {
            if(!buffer.empty()) {
                tokens.push_back(buffer);
                buffer.clear();
            }
            tokens.push_back(string(1,c));
        }
        else {
            buffer += c;
        }
    }

    if(!buffer.empty()) {
        tokens.push_back(buffer);
    }

    return tokens;
}

vector<Token> analisaToken(const vector<string>& palavras) {
    vector<Token> tokens;

    for (const auto& palavra : palavras) {
        tokens.push_back(classificaPalavra(palavra));
    }
    return tokens;
}

int main() {
    setlocale (LC_ALL, "");
    string texto;
    ifstream arquivo("programa.c");
    vector<string> palavras;
    string linha;

    while(getline(arquivo, linha)) {
        vector<string> tokensLinha = extraiTokens(linha);
        palavras.insert(palavras.end(), tokensLinha.begin(), tokensLinha.end());
    }

    vector<Token> tokens = analisaToken(palavras);

    bool temDesconhecido = false;
    for (const auto& token : tokens) {
        if (token.tipo == TipoDeToken::Desconhecido) {
            cout << "Erro léxico: \"" << token.texto << "\" não reconhecido.";
            return 0;
        }
    }

    for (const auto& token : tokens) {
        switch (token.tipo) {
            case TipoDeToken::PalavraImp: {
            string maisculas = token.texto;
            transform(maisculas.begin(), maisculas.end(), maisculas.begin(), [](unsigned char c) {return toupper(c); });
            cout << "<" << maisculas << "> ";
            break;
            }

            case TipoDeToken::Variavel:
            cout << "<ID, \"" << token.texto << "\"> ";
            break;

            case TipoDeToken::Numero:
            cout << "<NUM, \"" << token.texto << "\"> ";
            break;

            case TipoDeToken::Operador:
            if (token.texto == "=") {
                cout << "<ATRIB> ";
            }
            else if (token.texto == "!=") {
                cout << "<DIFERENTE> ";
            }
            else if (token.texto == "==") {
                cout << "<IGUAL> ";
            }
            else if (token.texto == "+") {
                cout << "<MAIS> ";
            }
            else if (token.texto == "++") {
                cout << "<MAISMAIS> ";
            }
            else if (token.texto == "-") {
                cout << "<MENOS> ";
            }
            else if (token.texto == "*") {
                cout << "<MULTIPLICA> ";
            }
            else if (token.texto == "/") {
                cout << "<DIVIDE> ";
            }
            else if (token.texto == ">") {
                cout << "<MAIOR> ";
            }
            else if (token.texto == "<") {
                cout << "<MENOR> ";
            }
            else if (token.texto == "%") {
                cout << "<MOD> ";
            }
            break;

            case TipoDeToken::Delimitador:
            if (token.texto == ";") {
                cout << "<PEV> ";
            }
            else if (token.texto == "(") {
                cout << "<LPAR> ";
            }
            else if (token.texto == ")") {
                cout << "<RPAR> ";
            }
            else if (token.texto == "{") {
                cout << "<LCHAVES> ";
            }
            else if (token.texto == "}") {
                cout << "<RCHAVES> ";
            }
            break;

            case TipoDeToken::LiteralChar:
                cout << "<LETRA, " << token.texto << "> ";
            break;

            default:
                cout << "Desconhecido";

        }
    }

return 0;

}

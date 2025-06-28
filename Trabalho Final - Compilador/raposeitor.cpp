#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

vector<vector<string> > prog;
int r[2048];
int t[2048];

int *getend(string &s) {
    char letra; int num;
    sscanf(s.c_str(),"%%%c%d", &letra, &num);
    if (letra=='r') return &r[num];
    else return &t[num];
}

int getval(string &s) {
    if (s[0]=='%') return *(getend(s));
    else {
        int num;
        sscanf(s.c_str(),"%d", &num);
        return num;
    }
}

int getposrot(string &r) {
    for (int i=0;i<(int)prog.size();i++)
        if (prog[i][0]=="label" and prog[i][1]==r)
            return i;
    return prog.size();
}

int main(int argc, char *argv[]) {

    if (argc != 2) {
        cout << "Uso: " << argv[0] << " [arquivo.rap]" << endl;
        return 1;
    }

    FILE *f;
    if (!strcmp(argv[1],"-"))
        f = stdin;
    else
        f = fopen(argv[1],"r");
    if (f==NULL) {
        cout << "Erro ao abrir arquivo." << endl;
        return 1;
    }

    // carrega o programa
    char linha[2048];
    while (fgets(linha,2048,f)!=NULL) {
        vector<string> instr;
        char *c = strtok(linha," \r\n");
        if (c != NULL and !strcmp(c,"printf")) {
            string s = c;
            instr.push_back(s);
            c[strlen(c)]=' ';
            int ini, fim;
            for (int i=0;linha[i];i++)
                if (linha[i]=='"') {
                    ini=i;
                    break;
                }
            for (int i=ini+1;linha[i];i++)
                if (linha[i]=='"' and linha[i-1]!='\\') {
                    fim=i;
                    break;
                }
            s = "";
            for (int i=ini+1;i<fim;i++)
                s = s + linha[i];
            instr.push_back(s);
        } else {
            while (c != NULL) {
                if (c[0]==';') break; // comentario
                string s = c;
                instr.push_back(s);
                c = strtok(NULL, " \r\n");
            }
        }
        while (instr.size() < 4) instr.push_back("nop"); // filler
        prog.push_back(instr);

    }

    if (f != stdin) fclose(f);

    // executa o programa
    int pc = 0;
    while (pc < (int)prog.size()) {
        int *dest = getend(prog[pc][1]);
        int a = getval(prog[pc][2]);
        int b = getval(prog[pc][3]);
        if (prog[pc][0] == "mov") {
            *dest = a;
            pc++;
        } else if (prog[pc][0] == "read") {
            cin >> *dest;
            pc++;
        } else if (prog[pc][0] == "label") {
            pc++; // ignora
        } else if (prog[pc][0] == "less") {
            *dest = (a < b ? 1 : 0);
            pc++;
        } else if (prog[pc][0] == "greater") {
            *dest = (a > b ? 1 : 0);
            pc++;
        } else if (prog[pc][0] == "lesseq") {
            *dest = (a <= b ? 1 : 0);
            pc++;
        } else if (prog[pc][0] == "greatereq") {
            *dest = (a >= b ? 1 : 0);
            pc++;
        } else if (prog[pc][0] == "equal") {
            *dest = (a == b ? 1 : 0);
            pc++;
        } else if (prog[pc][0] == "diff") {
            *dest = (a != b ? 1 : 0);
            pc++;
        } else if (prog[pc][0] == "jf") {
            int val = getval(prog[pc][1]);
            if (val == 0) pc = getposrot(prog[pc][2]);
            else pc++;
        } else if (prog[pc][0] == "jt") {
            int val = getval(prog[pc][1]);
            if (val != 0) pc = getposrot(prog[pc][2]);
            else pc++;
        } else if (prog[pc][0] == "printf") {
            string s = prog[pc][1];
            for (int i=0;s[i];i++)
                if (s[i]=='\\' and s[i+1]=='n') {
                    cout << endl;
                    i++;
                } else
                    cout << s[i];
            pc++;
        } else if (prog[pc][0] == "printv") {
            cout << getval(prog[pc][1]);
            pc++;
        } else if (prog[pc][0] == "add") {
            *dest = a+b;
            pc++;
        } else if (prog[pc][0] == "sub") {
            *dest = a-b;
            pc++;
        } else if (prog[pc][0] == "mult") {
            *dest = a*b;
            pc++;
        } else if (prog[pc][0] == "div") {
            *dest = a/b;
            pc++;
        } else if (prog[pc][0] == "mod") {
            *dest = a%b;
            pc++;
        } else if (prog[pc][0] == "jump") {
            pc = getposrot(prog[pc][1]);
        } else if (prog[pc][0] == "and") {
            *dest = ( ((a != 0) and (b != 0)) ? 1 : 0 );
            pc++;
        } else if (prog[pc][0] == "or") {
            *dest = ( ((a != 0) or (b != 0)) ? 1 : 0 );
            pc++;
        } else if (prog[pc][0] == "not") {
            *dest = ( (a==0) ? 1 : 0 );
            pc++;
        } else if (prog[pc][0] == "store" or prog[pc][0] == "load") {
            int val = getval(prog[pc][1]);
            int base=0, desl=getval(prog[pc][2]);
            string aux = prog[pc][2];
            for (int i=0;i<(int)aux.size();i++)
                if (aux[i]=='(') {
                    string tt = aux.substr(i+1, aux.size());
                    base = getval(tt);
                    break;
                }
            if (prog[pc][0] == "store")
                r[base+desl] = val;
            else
                *dest = r[base+desl];
            pc++;
        } else if (prog[pc][0] == "nop") {
            pc++;
        } else {
            cout << "Instrucao invalida: " << prog[pc][0] << endl;
            break;
        }
    }

    return 0;
}

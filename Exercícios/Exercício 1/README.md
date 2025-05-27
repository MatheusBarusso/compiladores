# Analisador Léxico para a Linguagem C

## Descrição

Este projeto consiste na implementação de um **analisador léxico** para a linguagem C, desenvolvido manualmente em **C ou C++**. O programa recebe como entrada um código fonte em C e gera como saída a **lista de tokens reconhecidos**.

---

## Exemplo de Entrada

```c
int main ( ) {
    int variavel = -42 ;
    char mander ;
    for ( int i = 0 ; i < n ; i ++ ) {
        if ( i % 2 == variavel + 30 )
            mander = ’f’ ;
        else
            mander = ’X’ ;
    }
}
```

---

## Exemplo de Saída

```text
<INT> <ID, "main"> <LPAR> <RPAR> <LCHAVES>
<INT> <ID, "variavel"> <ATRIB> <NUM, "-42">
<PEV> <CHAR> <ID, "mander"> <PEV> <FOR>
<LPAR> <INT> <ID, "i"> <ATRIB> <NUM, "0">
<PEV> <ID, "i"> <RCHAVES> <ID, "n"> <PEV>
<ID, "i"> <MAISMAIS> <RPAR> <LCHAVES> <IF>
<LPAR> <ID, "i"> <MOD> <NUM, "2"> <IGUAL>
<ID, "variavel"> <MAIS> <NUM, "30"> <RPAR>
<ID, "mander"> <ATRIB> <LETRA, "’f’"> <PEV>
<ELSE> <ID, "mander"> <ATRIB> <LETRA, "’X’">
<PEV> <RCHAVES> <RCHAVES>
```

---

## Regras e Requisitos

- O analisador deve ser implementado manualmente utilizando `if-else`, `switch-case` ou autômato finito determinístico (DFA).
- **Não utilizar ferramentas geradoras como `flex`**.
- Os seguintes tipos de tokens devem ser reconhecidos (entre outros): `INT`, `ID`, `NUM`, `CHAR`, `FOR`, `IF`, `ELSE`, `LETRA`, `ATRIB`, `MOD`, `MAIS`, `IGUAL`, `MAISMAIS`, `PEV`, `LPAR`, `RPAR`, `LCHAVES`, `RCHAVES`.
- Para os tokens com valor literal relevante (`ID`, `NUM`, `LETRA`), o texto original deve ser impresso junto.
- Utilize `enum` para definir os tipos de token, mas imprima seus nomes (e.g., `ID`, `NUM`, ...) em vez do valor numérico.
- Considere que os tokens na entrada são separados por espaços.
- O programa deve identificar **erros léxicos**, como caracteres inválidos.

### Exemplo de erro léxico:

Entrada:
```c
// Contém caractere inválido como o ponto de interrogação grego
```

Saída:
```text
Erro léxico: ";" não reconhecido.
```
---

## Compilação
```
g++ analisador_lexico.cpp -o analisador_lexico
```

## Licença

Este projeto é apenas para fins educacionais no contexto da disciplina de Compiladores.

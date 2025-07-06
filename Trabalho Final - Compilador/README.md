
# Trabalho de Compiladores - 2025/1

## Objetivo

Desenvolver um compilador para uma **linguagem de programação inventada**, que seja capaz de traduzir programas escritos nessa linguagem para o assembly da máquina **Raposeitor**.

---

## Requisitos da Linguagem Inventada

A linguagem que você inventar **deve permitir**:

- Declaração e manipulação de variáveis inteiras;
- Declaração e manipulação de vetores estáticos de inteiros;
- Leitura de valores do usuário;
- Impressão de valores e strings para o usuário;
- Escrita de seleções completas (`if/else`);
- Escrita de seleções parciais (`if`);
- Escrita de laços com condição (`while`);
- Escrita de laços de repetição simplificados (`for`);
- Aninhamento de laços e seleções;
- Escrita e uso de:
  - Expressões aritméticas: `+`, `-`, `*`, `/` (inteira), `%`
  - Expressões de comparação: `>`, `<`, `>=`, `<=`, `==`, `!=`
  - Expressões lógicas: `!`, `&&`, `||`
  - Uso de parênteses
- Comentários de linha (`//`)

**Não é necessário** implementar:
- Variáveis de tipos não inteiros;
- Matrizes, structs ou outras estruturas de dados complexas;
- Ponteiros;
- Funções;
- Manipulação de arquivos.

---

## Exemplo

### Código na linguagem inventada

```plaintext
var a: inteiro;
var b: inteiro;
var maior: inteiro; // declaração

leia(a);
leia(b);
se a > b entao {
  maior <- a;
} senao {
  maior <- b;
}

print("O maior eh ", maior, "\n");
```

---

## Raposeitor

Seu compilador deverá gerar código em **assembly do Raposeitor**, uma máquina com instruções de três endereços. A documentação da máquina está disponível no Moodle e inclui:

- Interpretadores: `raposeitor.cpp`, `raposeitor.py`
- Exemplos: códigos em Rapolang e seus equivalentes em assembly

> ⚠️ **Atenção**: não implemente um compilador para a linguagem Rapolang! Você deve criar a sua própria linguagem.

---

## Implementação

- O compilador deve ser implementado em **C ou C++**;
- Pode-se usar qualquer técnica de parser (manual, `flex/bison`, etc.);
- É permitido restringir aspectos da linguagem para facilitar a implementação (ex: exigir delimitadores `{}` mesmo para blocos de uma linha);
- O compilador **deve identificar e apontar erros**:
  - Léxicos
  - Sintáticos
  - Semânticos
- O código assembly **não precisa ser otimizado**, apenas correto e funcional com os interpretadores fornecidos.

## Execução

No terminal, na pasta dos arquivos rodar os seguintes comandos:

```
make clean && make
```
```
./analisador "nome do arquivo".ppc > saida.rps
```
```
./raposeitor saida.rps
```


---

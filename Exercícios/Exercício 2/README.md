# Parser LL(1) para Expressões Booleanas

## Descrição

Este projeto consiste na implementação de um **parser LL(1)**, desenvolvido em **C ou C++**, para expressões booleanas baseadas na gramática definida a seguir. O programa deve validar se uma expressão está sintaticamente correta de acordo com a gramática especificada.

---

## Gramática Original

(Símbolos terminais: `i`, `=`, `e`, `o`, `n`, `(`, `)`)

```
A → i = E  
E → E e D | D  
D → D o L | L  
L → i | n i | (E) | n(E)
```

### Observações

- `i` representa identificadores;
- `e` representa a conjunção lógica (e);
- `o` representa a disjunção lógica (ou);
- `n` representa a negação lógica (não).

---

## Exemplo de Entradas e Saídas

### Entrada
```
i=(io(ieni))
```

### Saída
```
entrada valida
```

---

### Entrada
```
i=(i(ieni))
```

### Saída
```
erro sintatico
```

---

### Entrada
```
i=ioien(ioi)
```

### Saída
```
entrada valida
```

---

## Requisitos

- A gramática fornecida **não é LL(1)**. Antes de implementar o parser, transforme a gramática em uma forma compatível com análise LL(1).
- O parser deve utilizar **tabela de predição LL(1)**.
- A entrada será um programa sem espaços entre os símbolos.

---

## Compilação

```
g++ parser_LL1.cpp -o parser_LL1
```

## Licença

Este projeto é apenas para fins educacionais no contexto da disciplina de Compiladores.

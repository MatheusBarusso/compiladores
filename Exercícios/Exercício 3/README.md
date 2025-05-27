# Parser LR(0) para Expressões em Notação Pós-Fixa

## Descrição

Este projeto consiste na implementação de um **parser LR(0)**, desenvolvido em **C ou C++**, para expressões numéricas em **notação pós-fixa** (apenas com operação de soma). O parser irá validar se uma entrada está sintaticamente correta conforme a gramática fornecida.

---

## Gramática Original

(Símbolos terminais: `n`, `+`)

```
E → E E S | n  
S → +
```

### Observações

- `n` representa um número;
- A gramática processa expressões **pós-fixadas**, como `n n +` (em vez de `n + n`).

---

## Exemplo de Entradas e Saídas

### Entrada
```
nn+
```

### Saída
```
entrada valida
```

---

### Entrada
```
n+n
```

### Saída
```
erro sintatico
```

---

### Entrada
```
nnn+n++
```

### Saída
```
entrada valida
```

---

## Requisitos

- A implementação deve ser um **parser LR(0)**.
- Deve ser gerada a **gramática aumentada e numerada**, o **autômato LR(0)** e a **tabela de predição LR(0)**.

---

## Licença

Este projeto é apenas para fins educacionais no contexto da disciplina de Compiladores.

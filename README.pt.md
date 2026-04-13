# push_swap

Um projeto de algoritmo de ordenação da [42 School](https://www.42network.org/) — ordenar uma pilha de inteiros usando duas pilhas e um conjunto limitado de operações, com o menor número de movimentos possível.

---

## O que é o push_swap?

O programa recebe uma lista de inteiros como argumentos e imprime a sequência de operações necessária para os ordenar de forma crescente usando duas pilhas: **pilha A** (entrada) e **pilha B** (auxiliar).

O desafio é ordenar os dados com o menor número de operações possível.

---

## Operações permitidas

| Operação | Descrição |
|----------|-----------|
| `sa` | Troca os dois primeiros elementos da pilha A |
| `sb` | Troca os dois primeiros elementos da pilha B |
| `ss` | `sa` e `sb` em simultâneo |
| `pa` | Move o topo da pilha B para o topo da pilha A |
| `pb` | Move o topo da pilha A para o topo da pilha B |
| `ra` | Roda a pilha A para cima (o primeiro elemento passa para o fim) |
| `rb` | Roda a pilha B para cima |
| `rr` | `ra` e `rb` em simultâneo |
| `rra` | Roda a pilha A para baixo (o último elemento passa para o início) |
| `rrb` | Roda a pilha B para baixo |
| `rrr` | `rra` e `rrb` em simultâneo |

---

## Algoritmo

Esta implementação usa um **algoritmo de custo mínimo** (também conhecido como Turkish Sort):

**Fase 1 — Empurrar para B:**
- Move elementos de A para B um a um
- Para cada elemento, calcula o custo das 4 combinações de rotação possíveis (`ra`+`rb`, `rra`+`rrb`, `ra`+`rrb`, `rra`+`rb`)
- Move sempre o elemento com o menor custo total
- Continua até restar apenas 3 elementos em A

**Fase 2 — Ordenar os 3 restantes em A:**
- Aplica uma ordenação ótima codificada para 3 elementos (máximo 2 operações)

**Fase 3 — Empurrar de volta para A:**
- Para cada elemento em B, encontra a posição correta em A
- Calcula novamente a rotação de menor custo e empurra de volta
- Repete até B estar vazia

**Fase 4 — Rotação final:**
- Roda A para que o menor elemento fique no topo

**Casos especiais:**
- 2 elementos: um único `sa` se necessário
- Já ordenado: nenhuma saída

---

## Estrutura do projeto

```
push_swap/
├── include/
│   └── push_swap.h              # structs e protótipos de funções
├── src/
│   ├── main.c                   # ponto de entrada
│   ├── algorithm.c              # lógica principal de ordenação
│   ├── interpreter_args.c       # interpretação dos argumentos
│   ├── checkers/
│   │   ├── check_double_number.c
│   │   ├── check_is_number.c
│   │   └── check_order.c
│   ├── operations/
│   │   ├── operations_a.c       # sa, pa, ra, rra
│   │   ├── operations_b.c       # sb, pb, rb, rrb
│   │   └── operations_double.c  # ss, rr, rrr
│   ├── rotations/
│   │   ├── rotate_type.c        # cálculo de custo
│   │   ├── rotate_case_ab.c     # casos de rotação A→B
│   │   ├── rotate_case_ba.c     # casos de rotação B→A
│   │   └── rotate_and_push.c    # aplica a melhor rotação + push
│   ├── stack_functions/
│   │   ├── find_index.c
│   │   ├── find_place_a.c
│   │   ├── find_place_b.c
│   │   ├── free_stack.c
│   │   ├── ft_add_back.c
│   │   ├── ft_stack_new.c
│   │   ├── lst_last.c
│   │   ├── lst_max.c
│   │   ├── lst_min.c
│   │   └── lst_size.c
│   └── utils/
│       ├── exit_error.c
│       ├── free_str.c
│       ├── ft_atoi.c
│       ├── ft_isdigit.c
│       ├── ft_printf.c
│       ├── ft_split.c
│       └── ft_strlen.c
└── Makefile
```

---

## Como compilar e correr

```bash
# Compilar
make

# Correr com argumentos individuais
./push_swap 5 3 1 4 2

# Correr com string entre aspas
./push_swap "5 3 1 4 2"

# Verificar o número de operações
./push_swap 5 3 1 4 2 | wc -l
```

**Tratamento de erros** — o programa escreve `Error` no stderr e termina para:
- Argumentos não inteiros
- Overflow de inteiro
- Valores duplicados

---

## Testes

Podes verificar se a saída está correta passando-a por um checker:

```bash
# Usando o checker da 42 (se disponível)
./push_swap 5 3 1 4 2 | ./checker 5 3 1 4 2

# Gerar um teste aleatório
ARG=$(shuf -i 1-100 -n 5 | tr '\n' ' ') && ./push_swap $ARG | wc -l
```

**Número de operações esperado (escala de avaliação da 42):**

| Tamanho da entrada | Máximo de operações para nota máxima |
|--------------------|--------------------------------------|
| 3 números          | ≤ 3 |
| 5 números          | ≤ 12 |
| 100 números        | ≤ 700 |
| 500 números        | ≤ 5500 |

---

## O que aprendi

- Implementar e manipular **listas ligadas** em C
- Desenhar um **algoritmo greedy** baseado em custo mínimo
- Tratar **casos extremos** e validação de input de forma robusta
- Trabalhar com **estruturas de dados de duas pilhas**
- Otimizar operações combinando movimentos simultâneos (`ss`, `rr`, `rrr`)

---

## Tecnologias

![C](https://img.shields.io/badge/linguagem-C-blue)
![42](https://img.shields.io/badge/escola-42-black)
![Makefile](https://img.shields.io/badge/build-Makefile-lightgrey)

---

## Licença

MIT

---

🇬🇧 [English version](README.md)
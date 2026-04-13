# push_swap

A sorting algorithm project from [42 School](https://www.42network.org/) — sort a stack of integers using two stacks and a limited set of operations, with the minimum number of moves possible.

---

## What is push_swap?

The program receives a list of integers as arguments and outputs the sequence of operations needed to sort them in ascending order using two stacks: **stack A** (input) and **stack B** (auxiliary).

The challenge is to sort the data with as few operations as possible.

---

## Allowed operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first two elements of stack A |
| `sb` | Swap the first two elements of stack B |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push the top of stack B onto stack A |
| `pb` | Push the top of stack A onto stack B |
| `ra` | Rotate stack A upward (first element becomes last) |
| `rb` | Rotate stack B upward |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack A (last element becomes first) |
| `rrb` | Reverse rotate stack B |
| `rrr` | `rra` and `rrb` simultaneously |

---

## Algorithm

This implementation uses a **minimum cost algorithm** (also known as Turkish Sort):

**Phase 1 — Push to B:**
- Push elements from A to B one by one
- For each element, calculate the cost of all 4 possible rotation combinations (`ra`+`rb`, `rra`+`rrb`, `ra`+`rrb`, `rra`+`rb`)
- Always move the element with the lowest total cost
- Continue until only 3 elements remain in A

**Phase 2 — Sort the 3 remaining in A:**
- Apply a hardcoded optimal sort for 3 elements (max 2 operations)

**Phase 3 — Push back to A:**
- For each element in B, find its correct position in A
- Again calculate the minimum cost rotation and push back
- Repeat until B is empty

**Phase 4 — Final rotation:**
- Rotate A so the smallest element ends up on top

**Special cases:**
- 2 elements: single `sa` if needed
- Already sorted: no output

---

## Project structure

```
push_swap/
├── include/
│   └── push_swap.h              # all structs and function prototypes
├── src/
│   ├── main.c                   # entry point
│   ├── algorithm.c              # core sorting logic
│   ├── interpreter_args.c       # argument parsing
│   ├── checkers/
│   │   ├── check_double_number.c
│   │   ├── check_is_number.c
│   │   └── check_order.c
│   ├── operations/
│   │   ├── operations_a.c       # sa, pa, ra, rra
│   │   ├── operations_b.c       # sb, pb, rb, rrb
│   │   └── operations_double.c  # ss, rr, rrr
│   ├── rotations/
│   │   ├── rotate_type.c        # cost calculation
│   │   ├── rotate_case_ab.c     # A→B rotation cases
│   │   ├── rotate_case_ba.c     # B→A rotation cases
│   │   └── rotate_and_push.c    # apply best rotation + push
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

## How to compile and run

```bash
# Compile
make

# Run with individual arguments
./push_swap 5 3 1 4 2

# Run with a quoted string
./push_swap "5 3 1 4 2"

# Check the number of operations
./push_swap 5 3 1 4 2 | wc -l
```

**Error handling** — the program writes `Error` to stderr and exits for:
- Non-integer arguments
- Integer overflow
- Duplicate values

---

## Testing

You can verify the output is correct by piping it to a checker:

```bash
# Using the 42 checker (if available)
./push_swap 5 3 1 4 2 | ./checker 5 3 1 4 2

# Generate a random test
ARG=$(shuf -i 1-100 -n 5 | tr '\n' ' ') && ./push_swap $ARG | wc -l
```

**Expected operation counts (42 grading scale):**

| Input size | Max operations for full score |
|------------|-------------------------------|
| 3 numbers  | ≤ 3 |
| 5 numbers  | ≤ 12 |
| 100 numbers | ≤ 700 |
| 500 numbers | ≤ 5500 |

---

## What I learned

- Implementing and manipulating **linked lists** in C
- Designing a **greedy algorithm** based on minimum cost
- Handling **edge cases** and input validation robustly
- Working with **two-stack data structures**
- Optimizing operations by combining simultaneous moves (`ss`, `rr`, `rrr`)

---

## Built with

![C](https://img.shields.io/badge/language-C-blue)
![42](https://img.shields.io/badge/school-42-black)
![Makefile](https://img.shields.io/badge/build-Makefile-lightgrey)

---

## License

MIT

---

🇵🇹 [Versão em Português](README.pt.md)
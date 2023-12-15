#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>

typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void pop_opcode(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */

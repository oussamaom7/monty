#include "monty.h"
#include <stdio.h>

/**
 * pint_opcode - Handles the pint opcode.
 * @stack: Pointer to the stack
 * @line_number: Line number in the Monty file
 */
void pint_opcode(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}

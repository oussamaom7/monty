#include "monty.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static const instruction_t opcodes[] = {
    {"push", push_opcode},
    {"pall", pall_opcode},
    {"pint", pint_opcode},
    {"pop", pop_opcode},
    {NULL, NULL}
};

void execute_instruction(char *line, stack_t **stack)
{
    char *opcode, *value_str;
    int value;

    opcode = strtok(line, " \t\n");
    if (opcode == NULL || opcode[0] == '#')
        return;

    if (strcmp(opcode, "push") == 0)
    {
        value_str = strtok(NULL, " \t\n");
        if (value_str == NULL)
        {
            fprintf(stderr, "L%u: usage: push integer\n", 0);
            exit(EXIT_FAILURE);
        }

        value = atoi(value_str);
        push(stack, 0, value);
    }
    else if (strcmp(opcode, "pint") == 0)
    {
        pint_opcode(stack, 0);
    }
    else if (strcmp(opcode, "pop") == 0)
    {
        pop_opcode(stack, 0);
    }
    else
    {
        int i = 0;
        while (opcodes[i].opcode != NULL)
        {
            if (strcmp(opcodes[i].opcode, opcode) == 0)
            {
                opcodes[i].f(stack, 0);
                return;
            }
            i++;
        }

        fprintf(stderr, "L%d: unknown instruction %s\n", 0, opcode);
        exit(EXIT_FAILURE);
    }
}


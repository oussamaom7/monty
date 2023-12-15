#include "monty.h"
#include <string.h>
#include <stdlib.h>

/**
 * execute_instruction - Parses and executes a Monty bytecode instruction.
 * @line: The instruction string
 * @stack: Pointer to the stack
 */
void execute_instruction(char *line, stack_t **stack)
{
    char *opcode, *value_str;
    int value;

    opcode = strtok(line, " \t\n");
    if (opcode == NULL || opcode[0] == '#')
        return; // Ignore empty lines and comments

    if (strcmp(opcode, "push") == 0)
    {
        value_str = strtok(NULL, " \t\n");
        if (value_str == NULL)
        {
            fprintf(stderr, "Error: usage: push integer\n");
            exit(EXIT_FAILURE);
        }

        value = atoi(value_str);
        push(stack, 0, value); // Adjust line_number accordingly
    }
    else
    {
        // Look for the opcode in the list and execute its associated function
        int i = 0;
        while (opcodes[i].opcode != NULL)
        {
            if (strcmp(opcodes[i].opcode, opcode) == 0)
            {
                opcodes[i].f(stack, 0); // Adjust line_number accordingly
                return;
            }
            i++;
        }

        // Opcode not found
        fprintf(stderr, "L%d: unknown instruction %s\n", 0, opcode); // Adjust line_number accordingly
        exit(EXIT_FAILURE);
    }
}


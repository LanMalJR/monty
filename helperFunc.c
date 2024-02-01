#include "monty.h"

/**
 * get_opcode_function - Returns the function pointer for a given opcode.
 * @opcode: Opcode to check.
 * Return: Function pointer to the corresponding opcode function.
 */
void (*get_opcode_function(char *opcode))(stack_t **, unsigned int)
{
    instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {"add", add},
        {"nop", nop},
        {NULL, NULL}
    };

    int i = 0;

    while (instructions[i].opcode)
    {
        if (strcmp(opcode, instructions[i].opcode) == 0)
            return instructions[i].f;
        i++;
    }

    return NULL;
}

/**
 * free_stack - Frees a stack.
 * @stack: Double pointer to the head of the stack.
 */
void free_stack(stack_t **stack)
{
    stack_t *temp;

    while (*stack)
    {
        temp = *stack;
        *stack = temp->next;
        free(temp);
    }
}

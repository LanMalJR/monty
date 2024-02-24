#include "monty.h"

/* Function to push an element onto the stack */
void push(stack_t **stack, unsigned int line_number)
{
    stack_t *new_node;
    int value __attribute__((unused));

    if (!*stack)
    {
        *stack = malloc(sizeof(stack_t));
        if (!*stack)
        {
            fprintf(stderr, "Error: malloc failed\n");
            exit(EXIT_FAILURE);
        }
        (*stack)->n = line_number;
        (*stack)->prev = NULL;
        (*stack)->next = NULL;
    }
    else
    {
        new_node = malloc(sizeof(stack_t));
        if (!new_node)
        {
            fprintf(stderr, "Error: malloc failed\n");
            exit(EXIT_FAILURE);
        }
        new_node->n = line_number;
        new_node->prev = *stack;
        new_node->next = NULL;
        (*stack)->next = new_node;
        *stack = new_node;
    }
}

/* Function to print all elements of the stack */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;

    (void)line_number; /* Unused parameter */

    while (temp)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}
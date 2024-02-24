#define _GNU_SOURCE 
#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    stack_t *stack = NULL;
    char *line = NULL, *token = NULL;
    size_t len =  0;
    ssize_t read; 
    unsigned int line_number =  1;
    FILE *file;

    if (argc !=  2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return (EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return (EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1) 
    {
        line_number++;
        token = strtok(line, " \t\n");

        if (token == NULL || strlen(token) ==  0)
            continue;

        if (strcmp(token, "push") ==  0)
        {
            token = strtok(NULL, " \t\n");
            if (token == NULL || isspace((unsigned char)*token))
            {
                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                free_stack(stack); 
                fclose(file);
                free(line);
                return (EXIT_FAILURE);
            }
        }
    }

    free_stack(stack); 
    fclose(file);
    free(line);
    return (EXIT_SUCCESS); 
}
           
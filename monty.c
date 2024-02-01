#include "monty.h"

int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    stack_t *stack = NULL;
    unsigned int line_number = 0;
    char *opcode;
    void (*op_func)(stack_t **, unsigned int);

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;
        opcode = strtok(line, " \t\n");

        if (opcode && opcode[0] != '#')
        {
            op_func = get_opcode_function(opcode);
            if (op_func)
                op_func(&stack, line_number);
            else
                fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
        }
    }

    free(line);
    fclose(file);
    free_stack(&stack);

    return EXIT_SUCCESS;
}

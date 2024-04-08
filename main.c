#include "monty.h"

/**
 * main- entry point of program to execute monty 
 * 
 * @argc: count of arguments
 * @argv: arguments
 * 
 * Return: 0
 */

int main(int argc, char **argv)
{
	char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;
    stack_t *stack = NULL;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

	FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
    	fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (getline(&line, &len, file) != -1)
    {
        line_number++;

        char *opcode = strtok(line, " \n");

        if (strcmp(opcode, "push") == 0)
        {
            char *value_str = strtok(NULL, " \n");
            if (value_str == NULL)
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                free(line);
                fclose(file);
                exit(EXIT_FAILURE);
			}
            push(&stack, line_number);
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall(&stack, line_number);
        }

        else
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            free(line);
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }

    free(line);
    fclose(file);

    return EXIT_SUCCESS;
}
#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - Monty code interpreter
 * @argc: Number of arguments
 * @argv: Monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
    char *content;
    FILE *file;
    size_t size = 0;
    char *read_line = NULL;
    stack_t *stack = NULL;
    unsigned int counter = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    bus.file = file;

    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read_line = fgets(content, size, file)) != NULL)
    {
        content = NULL;
        size = 0;
        counter++;

        execute(read_line, &stack, counter, file);

        free(content);
    }

    free_stack(stack);
    fclose(file);

    return 0;
}

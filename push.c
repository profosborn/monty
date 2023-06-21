#include "monty.h"

/**
 * f_push - Pushes an element onto the stack or queue.
 * @head: Pointer to the head of the stack or queue.
 * @counter: Line number in the file.
 */
void f_push(stack_t **head, unsigned int counter)
{
    int value;

    if (bus.arg)
    {
        if (!isdigit(*bus.arg) && *bus.arg != '-' && *bus.arg != '+')
        {
            fprintf(stderr, "L%u: usage: push integer\n", counter);
            fclose(bus.file);
            free(bus.content);
            free_stack(*head);
            exit(EXIT_FAILURE);
        }

        value = atoi(bus.arg);
        if (bus.lifo == 0)
            addnode(head, value); // Add to the top of the stack (LIFO)
        else
            addqueue(head, value); // Add to the end of the stack (FIFO)
    }
    else
    {
        fprintf(stderr, "L%u: usage: push integer\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
}

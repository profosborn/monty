#include "monty.h"

/**
 * f_push - Pushes an element onto the stack or queue.
 * @head: Pointer to the head of the stack or queue.
 * @counter: Line number in the file.
 */
void f_push(stack_t **head, unsigned int counter)
{
    int value, i = 0;
    stack_t *new_node;

    if (bus.arg)
    {
        if (bus.arg[0] == '-')
            i++;

        while (bus.arg[i] != '\0')
        {
            if (!isdigit(bus.arg[i]))
            {
                fprintf(stderr, "L%u: usage: push integer\n", counter);
                fclose(bus.file);
                free(bus.content);
                free_stack(*head);
                exit(EXIT_FAILURE);
            }
            i++;
        }
    }
    else
    {
        fprintf(stderr, "L%u: usage: push integer\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    value = atoi(bus.arg);
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    new_node->n = value;
    new_node->prev = NULL;

    if (*head == NULL)
    {
        new_node->next = NULL;
        *head = new_node;
    }
    else
    {
        new_node->next = *head;
        (*head)->prev = new_node;
        *head = new_node;
    }
}

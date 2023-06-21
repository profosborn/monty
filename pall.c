#include "monty.h"

/**
 * f_pall - Prints all the elements in the stack.
 * @head: Pointer to the head of the stack.
 * @counter: Not used in this function.
 */
void f_pall(stack_t **head, unsigned int counter)
{
    stack_t *current_node;

    (void) counter;

    if (*head == NULL)
        return;

    current_node = *head;
    while (current_node != NULL)
    {
        printf("%d\n", current_node->n);
        current_node = current_node->next;
    }
}

#include "monty.h"

/**
 * f_sub - Subtracts the top element
 *         from the second top element of the stack.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number.
 */
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *aux;
	int sub, nodes;

	aux = *head;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	sub = aux->next->n - aux->n;
	aux->next->n = sub;
	*head = aux->next;
	free(aux);
}

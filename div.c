#include "monty.h"

/**
 * f_div - Divides the second top element
 *           of the stack by the top element.
 * @head: Pointer to the head of the stack.
 * @counter: Line number.
 */
void f_div(stack_t **head, unsigned int counter)
{
	stack_t *current;
	int stack_size = 0, quotient;

	current = *head;
	while (current)
	{
		current = current->next;
		stack_size++;
	}

	if (stack_size < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	current = *head;
	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	quotient = current->next->n / current->n;
	current->next->n = quotient;
	*head = current->next;
	free(current);
}

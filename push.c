#include "monty.h"

/**
 * f_push - Pushes an element onto the stack or queue.
 * @head: Pointer to the head of the stack or queue.
 * @counter: Line number in the file.
 */
void f_push(stack_t **head, unsigned int counter)
{
	if (bus.arg)
	{
		int i = 0;
		if (bus.arg[0] == '-')
			i++;

		while (bus.arg[i] != '\0')
		{
			if (!isdigit(bus.arg[i]))
			{
				fprintf(stderr, "L%d: usage: push integer\n", counter);
				fclose(bus.file);
				free(bus.content);
				free_stack(*head);
				exit(EXIT_FAILURE);
			}
			i++;
		}

		addnode(head, atoi(bus.arg));
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
}

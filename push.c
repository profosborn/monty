#include "monty.h"

/**
 * f_push - Pushes an element onto the stack or queue.
 * @head: Pointer to the head of the stack or queue.
 * @counter: Line number in the file.
 */
void f_push(stack_t **head, unsigned int counter)
{
	int value;

	if (!bus.arg)
	{
		fprintf(stderr, "L%u: usage: push integer\n", counter);
		exit(EXIT_FAILURE);
	}

	value = atoi(bus.arg);

	if (!is_valid_integer(bus.arg, value))
	{
		fprintf(stderr, "L%u: usage: push integer\n", counter);
		exit(EXIT_FAILURE);
	}

	if (bus.lifo == 0)
		addnode(head, value);
	else
		addqueue(head, value);
}

/**
 * is_valid_integer - Checks if a string represents a valid integer.
 * @str: String to be checked.
 * @value: Integer value obtained from the string.
 * Return: 1 if the string is a valid integer, 0 otherwise.
 */
int is_valid_integer(char *str, int value)
{
	int i = 0;

	if (str[i] == '-')
		i++;

	while (str[i] != '\0')
	{
		if (!isdigit(str[i]))
			return 0;
		i++;
	}

	if (value == 0 && strcmp(str, "0") != 0)
		return 0;

	return 1;
}

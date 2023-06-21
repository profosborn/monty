/**
 * f_push - Pushes an element onto the stack or queue.
 * @head: Pointer to the head of the stack or queue.
 * @counter: Line number in the file.
 */
void f_push(stack_t **head, unsigned int counter)
{
	int value, i = 0;

	if (!bus.arg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		exit(EXIT_FAILURE);
	}

	if (bus.arg[0] == '-')
		i++;

	while (bus.arg[i] != '\0')
	{
		if (!isdigit(bus.arg[i]))
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			exit(EXIT_FAILURE);
		}
		i++;
	}

	value = atoi(bus.arg);

	if (bus.lifi == 0)
		addnode(head, value);
	else
		addqueue(head, value);
}

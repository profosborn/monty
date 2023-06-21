/**
 * f_div - Performs division of the top two elements of the stack.
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
        fprintf(stderr, "L%d: Unable to perform division, stack is too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    current = *head;
    if (current->n == 0)
    {
        fprintf(stderr, "L%d: Division by zero is not allowed\n", counter);
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

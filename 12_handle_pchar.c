#include "monty.h"

/**
 * handle_pchar - prints the character at the top of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void handle_pchar(stack_t **head, unsigned int counter)
{
	stack_t *value = *head;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", counter);
		free_all(head);
	}

	if (value->n < 0 || value->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", counter);
		free_all(head);
	}

	printf("%c\n", value->n);
}

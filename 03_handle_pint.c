#include "monty.h"
/**
 * handle_pint - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void handle_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		free_all(head);
	}
	printf("%d\n", (*head)->n);
}

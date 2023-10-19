#include "monty.h"
/**
 * handle_pop - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void handle_pop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		free_all(head);
	}
	h = *head;
	*head = h->next;
	free(h);
}

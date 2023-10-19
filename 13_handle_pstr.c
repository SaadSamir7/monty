#include "monty.h"

/**
 * handle_pstr - prints the string starting at the top of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void handle_pstr(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h && h->n != 0 && isprint(h->n))
	{
		printf("%c", h->n);
		h = h->next;
	}

	printf("\n");
}

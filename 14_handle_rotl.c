#include "monty.h"

/**
 * handle_rotl - rotates the stack to the top.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void handle_rotl(stack_t **head, unsigned int counter)
{
	stack_t *top, *second, *last;

	(void)counter;

	if (*head && (*head)->next)
	{
		top = *head;
		second = top->next;
		last = top;

		while (last->next)
		{
			last = last->next;
		}

		*head = second;
		second->prev = NULL;

		top->next = NULL;
		top->prev = last;
		last->next = top;
	}
}

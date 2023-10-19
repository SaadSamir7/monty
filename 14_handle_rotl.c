#include "monty.h"

/**
 * handle_rotl - rotates the stack to the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void handle_rotl(stack_t **head, unsigned int counter)
{
	stack_t *first = *head;
	stack_t *second = first->next;
	stack_t *last = *head;

	(void)counter;
	if (*head == NULL || (*head)->next == NULL)
	{
		/* The stack is empty or has only one element, no rotation needed. */
		return;
	}

	while (last->next != NULL)
	{
		last = last->next;
	}

	*head = second;
	first->next = NULL;
	second->prev = NULL;
	last->next = first;
	first->prev = last;
}
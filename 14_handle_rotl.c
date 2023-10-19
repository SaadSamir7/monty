#include "monty.h"

/**
 * handle_rotl - rotates the stack to the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void handle_rotl(stack_t **head, unsigned int counter)
{
	stack_t *new_head = (*head)->next;
	stack_t *last_node = *head;
	(void)counter;

	if (*head == NULL || (*head)->next == NULL)
		return;

	while (last_node->next != NULL)
	{
		last_node = last_node->next;
	}

	last_node->next = *head;
	(*head)->prev = last_node;
	(*head)->next = NULL;
	new_head->prev = NULL;
	*head = new_head;
}
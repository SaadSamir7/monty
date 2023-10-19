#include "monty.h"

/**
 * handle_rotr - rotates the stack to the bottom
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void handle_rotr(stack_t **head, unsigned int counter)
{
	stack_t *current = *head;

	(void)counter;
	if (*head == NULL || (*head)->next == NULL)
		return;

	while (current->next != NULL)
	{
		current = current->next;
	}
	current->prev->next = NULL;
	current->prev = NULL;
	current->next = *head;
	(*head)->prev = current;
	*head = current;
}
#include "monty.h"

/**
* free_stack - frees a doubly linked list
* @head: head of the stack
*/

void free_stack(stack_t *head)
{
	stack_t *new_node;

	new_node = head;
	while (head)
	{
		new_node = head->next;
		free(head);
		head = new_node;
	}
}

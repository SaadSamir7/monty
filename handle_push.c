#include "monty.h"

/**
* handle_push - Pushes an element onto the stack.
* @stack: Double pointer to the head of the stack.
* @line_number: Line number of the instruction in the Monty file.
*/
void handle_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	(void)line_number;
	if (stack == NULL || *stack == NULL)
	{
		exit(EXIT_FAILURE);
	}

	if (head == NULL)
	{
		head = *stack;
	}
	else
	{
		new_node = head;
		head = *stack;
		head->next = new_node;
		new_node->prev = head;
	}
}
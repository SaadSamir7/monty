#include "monty.h"

/**
 * handle_pall - Prints all the values on the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the instruction in the Monty file.
 */
void handle_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}


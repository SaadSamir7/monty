#include "monty.h"

/**
 * handle_pop - Removes the top element from the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the instruction in the Monty file.
 */
void handle_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_nodes();
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}


#include "monty.h"

/**
 * handle_sub - Subtracts the top element from the second.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the instruction in the Monty file.
 */
void handle_sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_nodes();
		fclose(head.file);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	handle_pop(stack, line_number);
}

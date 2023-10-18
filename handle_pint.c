#include "monty.h"

/**
 * handle_pint - Prints the value at the top of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the instruction in the Monty file.
 */
void handle_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_nodes();
		fclose(head.file);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

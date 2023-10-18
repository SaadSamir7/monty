#include "monty.h"

/**
 * handle_pall - Prints all the values on the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the instruction in the Monty file.
 */
void handle_pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    if (*stack == NULL)
    {
        printf("L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

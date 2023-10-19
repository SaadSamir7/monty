#include "monty.h"

/**
* handle_push - Pushes an element onto the stack.
* @stack: Double pointer to the head of the stack.
* @line_number: Line number of the instruction in the Monty file.
*/
void handle_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	if (stack == NULL)
		return;
	if (head.value == NULL || not_a_number(head.value))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_nodes();
		fclose(head.file);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_nodes();
		free(head.contant);
		fclose(head.file);
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(head.value);
	new_node->prev = NULL;
	new_node->next = *stack;
	*stack = new_node;
	if (new_node->next != NULL)
		(new_node->next)->prev = new_node;
}

/**
 * not_a_number - checks if a string is not a number
 * @s: string to check
 * Return: 0 if it is a number, 1 otherwise
 */
int not_a_number(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		if (s[i] < '0' || s[i] > '9')
		{
			if (i == 0 && s[0] == '-')
				continue;
			return (1);
		}
	return (0);
}

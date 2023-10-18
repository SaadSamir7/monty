#include "monty.h"

/**
 * free2d - Frees a 2 dimensional array.
 * @tokens: The 2 dimensional array to be freed.
 */

void free2d(char **tokens)
{
	int i;

	if (tokens == NULL)
		return;

	for (i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
		tokens[i] = NULL;
	}
	free(tokens);
}


/**
 * free_nodes - Frees nodes in the stack.
 */

void free_nodes(void)
{
	stack_t *tmp;

	if (head.stack == NULL)
		return;

	while (head.stack != NULL)
	{
		tmp = head.stack;
		head.stack = head.stack->next;
		free(tmp);
	}
}

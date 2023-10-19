#include "monty.h"

/**
 * handle_mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/

void handle_mod(stack_t **head, unsigned int counter)
{
	stack_t *new_node;
	int len = 0, aux;

	new_node = *head;
	while (new_node)
	{
		new_node = new_node->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		free_all(head);
	}
	new_node = *head;
	if (new_node->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		free_all(head);
	}
	aux = new_node->next->n % new_node->n;
	new_node->next->n = aux;
	*head = new_node->next;
	free(new_node);
}

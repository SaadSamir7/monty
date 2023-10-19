#include "monty.h"
/**
 * handle_add - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void handle_add(stack_t **head, unsigned int counter)
{
	stack_t *new_node;
	int len = 0, value;

	new_node = *head;
	while (new_node)
	{
		new_node = new_node->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		free_all(head);
	}
	new_node = *head;
	value = new_node->n + new_node->next->n;
	new_node->next->n = value;
	*head = new_node->next;
	free(new_node);
}

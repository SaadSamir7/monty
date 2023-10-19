#include "monty.h"
/**
  *handle_sub- sustration
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void handle_sub(stack_t **head, unsigned int counter)
{
	stack_t *new_node;
	int sus, nodes;

	new_node = *head;
	for (nodes = 0; new_node != NULL; nodes++)
		new_node = new_node->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		free_all(head);
	}
	new_node = *head;
	sus = new_node->next->n - new_node->n;
	new_node->next->n = sus;
	*head = new_node->next;
	free(new_node);
}

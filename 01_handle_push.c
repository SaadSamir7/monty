#include "monty.h"

/**
 * handle_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/

void handle_push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (heads.arg)
	{
		if (heads.arg[0] == '-')
			j++;
		for (; heads.arg[j] != '\0'; j++)
		{
			if (heads.arg[j] > 57 || heads.arg[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			free_all(head);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		free_all(head);
	}
	n = atoi(heads.arg);
	if (heads.check == 0)
		addNode(head, n);
	else
		addQueue(head, n);
}

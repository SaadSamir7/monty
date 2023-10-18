#include "monty.h"

char **splitString(char *contant, unsigned int cntr, int format)
{
	const char *delim = "\n ";
	char **tokens = NULL;

	(void)cntr;
	(void)format;
	tokens = malloc(sizeof(char *) * 2);
	if (tokens == NULL)
	{
		/*you have to edit this to funtion in the  future*/
		printf("Error: malloc failed\n");
		free2d(tokens);
		free(contant);
		exit(EXIT_FAILURE);
	}
	tokens[0] = strtok(contant, delim);
	if (tokens[0] == NULL)
		return (NULL);
	tokens[1] = strtok(NULL, delim);

	return (tokens);
}

void findFunc(char **tokens, unsigned int cntr, int format)
{
	int i, found;
	instruction_t opcodes[] = {
		{"push", handle_push},
		{"pall", handle_pall},
		{"pint", handle_pint},
		{"pop", handle_pop},
		{"swap", handle_swap},
		{"add", handle_add},
		{"nop", handle_nop},
		{"sub", handle_sub},
		{NULL, NULL}
	};

	for (found = 0, i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcodes[i].opcode, tokens[0]) == 0)
		{
			handleFunc(opcodes[i].f, tokens, cntr, format);
			found = 1;
		}
	}

	if (found == 0)
	{
		/*you have to edit this to funtion in the  future*/
		printf("L%d: unknown instruction %s\n", cntr, tokens[0]);
		free2d(tokens);
		exit(EXIT_FAILURE);
	}
}

void handleFunc(op_func func, char **tokens,unsigned int cntr, int format)
{
	stack_t *node = NULL;
	int flag, i;

	flag = 1;
	(void)format;
	if (strcmp(tokens[0], "push") == 0)
	{
		if (tokens[1] != NULL && tokens[1][0] == '-')
		{
			tokens[1] = tokens[1] + 1;
			flag = -1;
		}
		for (i = 0; tokens[1][i] != '\0'; i++)
		{
			if (isdigit(tokens[1][i]) == 0)
			{
				/*you have to edit this to funtion in the  future*/
				printf("L%d: usage: push integer\n", cntr);
				free2d(tokens);
				exit(EXIT_FAILURE);
			}
		}
		node = createNode(atoi(tokens[1]) * flag);
		if (node == NULL)
		{
			/*you have to edit this to funtion in the  future*/
			printf("Error: malloc failed\n");
			free2d(tokens);
			exit(EXIT_FAILURE);
		}
		free2d(tokens);
		func(&node, cntr);
	}
	else
		func(&head, cntr);

	if(tokens)
		free2d(tokens);
}

/**
 * createNode - Creates a new node for the stack.
 * @n: Value to store in the new node.
 * Return: A pointer to the newly created node.
 */

stack_t *createNode(int n)
{
    stack_t *new_node = malloc(sizeof(stack_t));

    if (new_node == NULL)
    {
        printf("Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = NULL;
    return (new_node);
}
#include "monty.h"

/**
 * findFunc - Finds the opcode.
 * @opCode: Opcode to find.
 * @value: Value to use in the function.
 * @cntr: Line number of the instruction in the Monty file.
 * @format: Format of the opcode.
 * Description: This function finds the opcode by comparing the opcode
 * passed as an argument with the opcodes in the struct.
 * Return: Nothing.
*/

void findFunc(char *opCode, char *value, unsigned int cntr, int format)
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
		if (strcmp(opcodes[i].opcode, opCode) == 0)
		{
			handleFunc(opcodes[i].f, opCode, value, cntr, format);
			found = 1;
		}
	}

	if (found == 0)
	{
		/*you have to edit this to funtion in the  future*/
		fprintf(stderr, "L%d: unknown instruction %s\n", cntr, opCode);
		free_nodes();
		fclose(head.file);
		exit(EXIT_FAILURE);
	}
}

/**
 * handleFunc - Handles the opcode.
 * @func: Pointer to the function to use.
 * @opCode: Opcode to handle.
 * @value: Value to use in the function.
 * @cntr: Line number of the instruction in the Monty file.
 * @format: Format of the opcode.
 * Description: This function handles the opcode by calling the function
 * passed as an argument.
 * Return: Nothing.
*/

void handleFunc(op_func func, char *opCode, char *value,
unsigned int cntr, int format)
{
	stack_t *node = NULL;
	int flag, i;

	flag = 1;
	(void)format;
	if (strcmp(opCode, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			flag = -1;
		}
		if (value == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", cntr);
			free_nodes();
			fclose(head.file);
			exit(EXIT_FAILURE);
		}
		for (i = 0; value[i] != '\0'; i++)
		{
			if (isdigit(value[i]) == 0)
			{
				/*you have to edit this to funtion in the future*/
				fprintf(stderr, "L%d: usage: push integer\n", cntr);
				free_nodes();
				free(head.contant);
				fclose(head.file);
				exit(EXIT_FAILURE);
			}
		}

		node = createNode(atoi(value) * flag);
		func(&node, cntr);
	}
	else
		func(&head.stack, cntr);

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
		fprintf(stderr, "Error: malloc failed\n");
		free_nodes();
		fclose(head.file);
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;

	return (new_node);
}

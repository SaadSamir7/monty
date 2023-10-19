#include "monty.h"
/**
* exe - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int exe(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", handle_push}, {"pall", handle_pall},
				{"pint", handle_pint},
				{"pop", handle_pop},
				{"swap", handle_swap},
				{"add", handle_add},
				{"nop", handle_nop},
				{"sub", handle_sub},
				{"div", handle_div},
				{"mul", handle_mul},
				{"mod", handle_mod},
				{"queue", add_queue},
				{"stack", add_stack},{"pchar", handle_pchar},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *opCode;

	opCode = strtok(content, " \n\t");
	if (opCode && opCode[0] == '#')
		return (0);
	heads.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && opCode)
	{
		if (strcmp(opCode, opst[i].opcode) == 0)
		{
			opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (opCode && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, opCode);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}

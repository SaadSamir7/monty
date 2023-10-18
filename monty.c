#include "monty.h"

stack_t *head = NULL;

int opCode(char *contant, unsigned int cntr, int format)
{
	char **tokens = NULL;


	if (contant == NULL)
	{
		/*you have to edit this to funtion in the  future*/
		printf("Error: malloc failed\n");
		free2d(tokens);
		free(contant);
		exit(EXIT_FAILURE);
	}
	tokens = splitString(contant, cntr, format);

	if (tokens == NULL)
	{
		free2d(tokens);
		return(format);
	}

	findFunc(tokens, cntr, format);
	free2d(tokens);
	return (format);
}

void readFile(FILE *readFile)
{
	int cntr = 0, format = 0;
	char *contant = NULL;
	size_t len = 0;

	while (getline(&contant, &len, readFile) != -1)
	{
		cntr++;
		format =  opCode(contant, cntr, format);
	}
	free(contant);
}

void oprationFile(char *filename)
{
	FILE *read = fopen(filename, "r");

	if (read == NULL || filename == NULL)
	{
		/*you have to edit this to funtion in the  future*/
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	readFile(read);
}

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		/*you have to edit this to funtion in the  future*/
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	oprationFile(argv[1]);
	return (0);
}
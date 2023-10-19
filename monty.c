#include "monty.h"

state_t head = INIT_STATE;

/**
 * opCode - find opcode
 * @contant: opcode
 * @cntr: line number
 * @format: format
 * Return: format
 */

int opCode(char *contant, unsigned int cntr, int format)
{
	const char *delim = "\n ";

	/*printf("contant: %s\n", contant);*/
	if (contant == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_nodes();
		exit(EXIT_FAILURE);
	}
	head.opCode = strtok(contant, delim);
	/*printf("opCode: %s\n", head.opCode);*/
	if (head.opCode == NULL)
		return (format);
	head.value = strtok(NULL, delim);
	/*rintf("value: %s\n", head.value);*/
	findFunc(head.opCode, head.value, cntr, format);
	return (format);
}

/**
 * readFile - read file
 * @readFile: file to read
 */

void readFile(FILE *readFile)
{
	int cntr = 0, format = 0;
	/*char *contant = NULL;*/
	size_t len = 0;

	for (cntr = 1; getline(&head.contant, &len, readFile) != -1; cntr++)
	{
		/*printf("format: \"%s\" \n", head.contant);*/
		format =  opCode(head.contant, cntr, format);
	}
	free(head.contant);
}

/**
 * oprationFile - open and read file
 * @filename: name of file
 */

void oprationFile(char *filename)
{
	head.file = fopen(filename, "r");

	if (head.file == NULL || filename == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		free_nodes();
		fclose(head.file);
		exit(EXIT_FAILURE);
	}
	/*printf("ffffffff2\n");*/
	readFile(head.file);
	fclose(head.file);
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
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/*printf("ffffffff1\n");*/
	oprationFile(argv[1]);
	free_nodes();
	return (0);
}

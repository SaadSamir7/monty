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
	char *opCode, *value;
	const char *delim = "\n ";

	/*printf("contant: %s\n", contant);*/
	if (contant == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_nodes();
		exit(EXIT_FAILURE);
	}
	opCode = strtok(contant, delim);
	/*printf("opCode: %s\n", opCode);*/
	if (opCode == NULL)
		return (format);
	value = strtok(NULL, delim);
	/*printf("value: %s\n", value);*/

	findFunc(opCode, value, cntr, format);
	return (format);
}

/**
 * readFile - read file
 * @readFile: file to read
 */

void readFile(FILE *readFile)
{
	int cntr = 0, format = 0;
	char *contant = NULL;
	size_t len = 0;

	while (getline(&contant, &len, readFile) != -1)
	{
		cntr++;
		/*printf("format: %s\n", contant);*/
		format =  opCode(contant, cntr, format);

	}
	free(contant);
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

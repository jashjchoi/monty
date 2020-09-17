#include "monty.h"
/**
* main - the main function to initiate monty
* @argc: argument count
* @argv: filename
* Return: EXIT_SUCCESS, EXIT_FAILURE if fails
*/
int main(int argc, char *argv[])
{
	char *filename;
	char *buff = NULL;
	size_t buffsize = 0;
	char *input_cmd;
	unsigned int line_number = 0;
	FILE *fp;
	stack_t *stack = NULL;

	filename = argv[1];
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (getline(&buff, &buffsize, fp) != -1)
	{
		input_cmd = strtok(buff, "\n");
		token_cmd(input_cmd, &stack, line_number);
		line_number++;
	}
	fclose(fp);
	free(buff);
	if (stack != NULL)
	{
		_free(&stack);
	}
	return (EXIT_SUCCESS);
}

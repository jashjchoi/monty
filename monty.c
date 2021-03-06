#include "monty.h"
/**
* main - the main function to initiate monty
* @argc: argument count
* @argv: filename
* Return: EXIT_SUCCESS, EXIT_FAILURE if fails
*/
int main(int argc, char *argv[])
{
	char *buff = NULL;
	size_t buffsize = 0;
	char *input_cmd;
	unsigned int line_number = 0;
	FILE *fp;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buff, &buffsize, fp) != -1)
	{
		input_cmd = strtok(buff, "\n");
		token_cmd(input_cmd, &stack, line_number);
		line_number++;
	}
	if (stack != NULL)
	{
		_free(&stack);
	}
	free(buff);
	fclose(fp);
	return (EXIT_SUCCESS);
}

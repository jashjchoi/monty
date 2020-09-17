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
	FILE *file;
	stack_t *stack = NULL;

	filename = argv[1];
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (getline(&buff, &buffsize, file) != -1)
	{
		input_cmd = strtok(buff, "\n");
		token_cmd(input_cmd, &stack, line_number);
		line_number++;
	}
	if (stack != NULL)
	{
		_free(&stack, line_number);
	}
	fclose(file);
	free(buff);
	return (EXIT_SUCCESS);
}

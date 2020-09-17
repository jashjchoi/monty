#include "monty.h"
/**
 * main - the main function to initiate monty
 * @argc: argument count
 * @argv: filename
 * Description: open file from argv[1] and get opcodes from file
 * Return: EXIT_SUCCESS, EXIT_FAILURE if fails
 */
int main(int argc, char *argv[])
{
	char *filename, *buf = NULL;
	size_t bufsize = 0;
	char *input;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	FILE *fp;

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
	while (getline(&buf, &bufsize, fp) != -1)
	{
		input = strtok(buf, "\n");
		tokenizer(input, &stack, line_number);
		line_number++;
	}
	fclose(fp);
	free(buf);
	if (stack != NULL)
	{
		free_stk(&stack, line_number);
	}
	return (EXIT_SUCCESS);
}

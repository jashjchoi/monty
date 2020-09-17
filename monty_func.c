#include "monty.h"
/**
 * tokenizer - parses the cmd from input line
 * @file: the name of the file
 * @stack: double pointer to top of the stack
 * Return: none
 */
void tokenizer(char *file, stack_t **stack)
{
	size_t len;
	ssize_t tokenizer;
	unsigned int num = 0;
	char *line = NULL;
	char *cmd;
	FILE *fd;

	fd = fopen(file, "r");
	if (!fd)
	{
		printf("Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	while ((tokenizer = getline(&line, &len, fd)) != -1)
	{
		cmd = strtok(line, DELIMS);
		num++;
		if (cmd)
		{
			check_cmd(stack, cmd, num);
		}
	}
	if (line)
	{
		free(line);
	}
	fclose(fd);
}
/**
 * check_cmd - checks if the cmd is one of opcodes
 * @stack: ptr of the head of stack
 * @op: the line with instruction/command
 * @line_num: a number of the line where the command was found
 * Return: none
 */
void check_cmd(stack_t **stack, char *op, unsigned int line_num)
{
	int i;
	instruction_t ops[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"nop", _nop},
		{NULL, NULL}
	};
	for (i = 0; ops[i].opcode; i++)
	{
		if (strcmp(op, ops[i].opcode) == 0)
		{
			ops[i].f(stack, line_num);
			return;
		}
	}
	if (strlen(op) != 0 && op[0] != '#')
	{
		printf("L%u: unknown instruction %s\n", line_num, op);
		exit(EXIT_FAILURE);
	}
}

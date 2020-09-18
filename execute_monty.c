#include "monty.h"
/**
* token_cmd - parses the cmd from input line
* @input: input filename
* @stack: double ptr to the head of stack
* @line_number: line number in file
* Return: none
*/
void token_cmd(char *input, stack_t **stack, unsigned int line_number)
{
	char *token;
	char *toks;

	token = strtok(input, " ");
	if (!token || *token == ' ' || *token == '\n' || *token == '#')
	{
		return;
	}
	if (strcmp(token, "push") == 0)
	{
		toks = token;
		token = strtok(NULL, " ");
		if (!is_number(token))
		{
			line_number++;
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			_free(stack);
			exit(EXIT_FAILURE);
		}
		global_var.temp = atoi(token);
		check_cmd(toks, stack, line_number);
	}
	else
	{
		check_cmd(token, stack, line_number);
	}
}
/**
* check_cmd - checks if the cmd is one of opcodes
* @token: the line with instruction/command
* @stack: ptr to the head of stack
* @line_number: line number in file
* Return: none
*/
void check_cmd(char *token, stack_t **stack, unsigned int line_number)
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
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"nop", _nop},
		{NULL, NULL}
	};
	for (i = 0; ops[i].opcode; i++)
	{
		if (strcmp(token, ops[i].opcode) == 0)
		{
			ops[i].f(stack, line_number);
			return;
		}
	}
	line_number++;
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
	_free(stack);
	exit(EXIT_FAILURE);
}

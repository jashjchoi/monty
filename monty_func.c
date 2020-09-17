#include "monty.h"
/**
 * tokenizer - parses the cmd from input line
 * @file: the name of the file
 * @stack: double pointer to top of the stack
 * Return: none
 */
void tokenizer(char *input, stack_t **stack, unsigned int line_number)
{
	char *token;
	char *tokens;

	token = strtok(input, " ");
	if (token == NULL || *token == ' ' || *token == '\n' || *token == '#')
	{
		return;
	}
	if (strcmp(token, "push") == 0)
	{
		tokens = token;
		token = strtok(NULL, " ");
		if (!is_number(token))
		{
			line_number++;
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free_stk(stack, line_number);
			exit(EXIT_FAILURE);
		}
		global_var.temp = atoi(token);
		check_cmd(tokens, stack, line_number);
	}
	else
	{
		check_cmd(token, stack, line_number);
	}
}
/**
* check_cmd - finds OpCode match and then executes the OpCode.
* @token: the line with instruction/command
* @stack: the stack.
* @line_number: a number of the line where the command was found
* Return: none
*/
void check_cmd(char *token, stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t op[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"nop", _nop},
		{NULL, NULL}
	};
    for (i = 0; op[i].opcode; i++)
	{
		if (strcmp(token, op[i].opcode) == 0)
		{
			op[i].f(stack, line_number);
			return;
		}
	}
	line_number++;
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
	free_stk(stack, line_number);
	exit(EXIT_FAILURE);
}

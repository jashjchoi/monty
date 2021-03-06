#include "monty.h"
/**
* _free - frees global variable
* @stack: double ptr to the head of stack
* Return: none
*/
void _free(stack_t **stack)
{
	stack_t *temp = NULL;

	if (stack == NULL || *stack == NULL)
	{
		return;
	}
	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
/**
* is_number - checks if the input string is a digit number
* @token: the string being checked
* Return: 1 if it's a digit, 0 if else
*/
int is_number(char *token)
{
	if (token == NULL)
	{
		return (0);
	}
	if (*token == '-')
	{
		token++;
	}
	while (*token != '\0')
	{
		if (!isdigit(*token))
		{
			return (0);
		}
		token++;
	}
	token++;
	return (1);
}
/**
* _nop - do nothing
* @stack: double pointer to the head of the stack
* @line_number: line number in file
* Return: none
*/
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
	;
}

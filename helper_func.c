#include "monty.h"
/**
* free_stk - frees global variable
* @stack: the stack.
* @line_number: the line number.
* Return: none
*/
void free_stk(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL)
		return;
	while (*stack != NULL)
    {
		_pop(stack, line_number);
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

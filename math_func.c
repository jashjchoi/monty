#include "monty.h"
/**
* _add - adds 2 elements of the stack.
* @stack: double ptr to the head of the stack
* @line_number: line number in file
* Return: none
*/
void _add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (!stack || !(*stack) || (*stack)->next == NULL)
	{
		line_number++;
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		_free(stack, line_number);
		exit(EXIT_FAILURE);
	}
	sum = global_var.temp;
	_pop(stack, line_number);
	sum += global_var.temp;
	_pop(stack, line_number);
	global_var.temp = sum;
	_push(stack, line_number);
}
/**
* _sub - subtracts the top element of the stack from the second top element
* @stack: double ptr to the head of the stack
* @line_number: line number in file
* Return: none
*/
void _sub(stack_t **stack, unsigned int line_number)
{
	int sub_diff;

	if (!stack || !(*stack) || (*stack)->next == NULL)
	{
		line_number++;
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		_free(stack, line_number);
		exit(EXIT_FAILURE);
	}

	sub_diff = global_var.temp;
	_pop(stack, line_number);
	sub_diff = global_var.temp - sub_diff;
	_pop(stack, line_number);
	global_var.temp = sub_diff;
	_push(stack, line_number);
}
/**
* _mul - multiplies the second top element of the stack with the top element
* @stack: double ptr to the head of the stack
* @line_number: line number in file
* Return: none
*/
void _mul(stack_t **stack, unsigned int line_number)
{
	int mul_product;

	if (!stack || !(*stack) || (*stack)->next == NULL)
	{
		line_number++;
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		_free(stack, line_number);
		exit(EXIT_FAILURE);
	}

	mul_product = global_var.temp;
	_pop(stack, line_number);
	mul_product = global_var.temp * mul_product;
	_pop(stack, line_number);
	global_var.temp = mul_product;
	_push(stack, line_number);
}
/**
* _div - divides the second top element of the stack by the top element
* @stack: double ptr to the head of the stack
* @line_number: line number in file
* Return: none
*/
void _div(stack_t **stack, unsigned int line_number)
{
	int div_result;
	stack_t *temp;

	if (!stack || !(*stack) || (*stack)->next == NULL)
	{
		line_number++;
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		_free(stack, line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	if (temp->n == 0)
	{
		line_number++;
		fprintf(stderr, "L%d: division by zero\n", line_number);
		_free(stack, line_number);
		exit(EXIT_FAILURE);
	}
	div_result = temp->next->n / temp->n;
	temp->next->n = div_result;
	_pop(stack, line_number);
	(*stack)->n = div_result;
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

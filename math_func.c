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
	stack_t *temp;

	if (!stack || !(*stack) || (*stack)->next == NULL)
	{
		line_number++;
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		_free(stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;

	sum = temp->n + temp->next->n;
	temp->next->n = sum;
	*stack = temp->next;
	free(temp);
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
	stack_t *temp;

	if (!stack || !(*stack) || (*stack)->next == NULL)
	{
		line_number++;
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		_free(stack);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	sub_diff = temp->next->n - temp->n;
	temp->next->n = sub_diff;
	*stack = temp->next;
	free(temp);
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
	stack_t *temp;

	if (!stack || !(*stack) || (*stack)->next == NULL)
	{
		line_number++;
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		_free(stack);
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	mul_product = temp->next->n * temp->n;
	temp->next->n = mul_product;
	*stack = temp->next;
	free(temp);
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
		_free(stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	if (temp->n == 0)
	{
		line_number++;
		fprintf(stderr, "L%d: division by zero\n", line_number);
		_free(stack);
		exit(EXIT_FAILURE);
	}
	div_result = temp->next->n / temp->n;
	temp->next->n = div_result;
	*stack = temp->next;
	free(temp);
}
/**
* _mod - rest of the division of 2nd top element by top element of the stack
* @stack: double pointer to the head of the stack
* @line_number: line number in file
* Return: none
*/
void _mod(stack_t **stack, unsigned int line_number)
{
	int mod_result;
	stack_t *temp;

	if (!stack || !(*stack) || (*stack)->next == NULL)
	{
		line_number++;
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		_free(stack);
		exit(EXIT_FAILURE);	
	}
	temp = *stack;
	if (temp->n == 0)
	{
		line_number++;
		fprintf(stderr, "L%d: division by zero\n", line_number);
		_free(stack);
		exit(EXIT_FAILURE);
	}
	mod_result = temp->next->n % temp->n;
	temp->next->n = mod_result;
	*stack = temp-> next;
	free(temp);
}

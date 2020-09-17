#include "monty.h"
/**
* _push - pushes new node to the stack
* @stack: double ptr to the head of the stack
* @line_number: line number of the file
* Return: none
*/
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	char *num;

	num = strtok(NULL, DELIMS);
	if (num == NULL)
	{
		printf("L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = atoi(num);
	node->prev = NULL;
	node->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = node;
	}
	*stack = node;
}
/**
* _pall - prints everything on stack
* @stack: beginning of stack
* @line_number: line number in file
* Return: none
*/
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void) line_number;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
* _pint - prints the top of the stack
* @stack: double ptr to the head of the stack
* @line_number: line number in file
* Return: none
*/
void _pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
* _pop - removes the element from the stack
* @stack: double ptr to the head of the stack
* @line_number: line number in file
* Return: none
*/
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%u't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
/**
* _swap - swaps the top 2 elements of the stack
* @stack: double ptr to the head of the stack
* @line_number: line number in file
* Return: none
*/
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;

	(*stack)->prev = temp;
	(*stack)->next = temp->next;

	temp->prev = NULL;

	if (temp->next)
	{
		temp->next->prev = *stack;
	}
	temp->next = *stack;
	*stack = temp;
}

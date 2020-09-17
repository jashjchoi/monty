#include "monty.h"
/**
* _push -  pushes new node to the stack
* @stack: double ptr to the head of the stack
* @line_number: line number in file
* Return: none
*/
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: unknown stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		_free(stack, line_number);
		exit(EXIT_FAILURE);
	}
	new_node->n = global_var.temp;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
/**
* _pall - prints everything on stack
* @stack: double ptr to the head of the stack
* @line_number: line number in file
* Return: none
*/
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *stack;
	while (temp != NULL)
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
		line_number++;
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		fprintf(stdout, "%d\n", (*stack)->n);
	}
}

/**
* _pop - removes the element from the stack
* @stack: double ptr to the head of the stack
* @line_number: line number in file
* Return: none
*/
void _pop(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		line_number++;
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		global_var.temp = (*stack)->n;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}
/**
* _swap - swaps the top 2 elements of the stack
* @stack: double ptr to the head of the stack
* @line_number: line number
* Return: none
*/
void _swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		line_number++;
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		_free(stack, line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

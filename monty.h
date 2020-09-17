#ifndef MONTY_H_
#define MONTY_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define DELIM " \n"
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Coding project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Coding project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
* struct var - struct for setup the temp global variable
* @temp: temp variable
*/
typedef struct var
{
	int temp;
} var_t;

/* Global OPcode variable */
extern var_t global_var;
var_t global_var;

/* Monty Interpreter functions */
void token_cmd(char *line, stack_t **stack, unsigned int line_number);
void check_cmd(char *token, stack_t **stack, unsigned int line_number);

/* helper functions */
void _free(stack_t **stack);
int is_number(char *token);

/* Stack manipulation functions */
/* push function */
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);

/* Calculatiion functions */
void _add(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
#endif /* __MONTY_H__ */

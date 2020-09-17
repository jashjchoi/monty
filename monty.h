#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#define DELIMS "\n \r\t"
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Global OPcode variable */
extern stack_t **global_ptr;

/* Monty Interpreter functions */
void tokenizer(char *file, stack_t **stack);
void check_cmd(stack_t **stack, char *op, unsigned int line_num);

/* helper functions */
void g_free(void);

/* Stack manipulation functions */
/* push function */
void _push(stack_t **stack, unsigned int line_number);
/* print all function */
void _pall(stack_t **stack, unsigned int line_number);
/* print first integer on stack */
void _pint(stack_t **stack, unsigned int line_number);
/* pop the stack */
void _pop(stack_t **stack, unsigned int line_number);
/* swap the top two on stack */
void _swap(stack_t **stack, unsigned int line_number);

/* Calculatiion functions */
void _add(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
/* a function that does nothing */
void _nop(stack_t **stack, unsigned int line_number);

#endif /* __MONTY_H__ */

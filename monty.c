#include "monty.h"
stack_t **global_ptr;
/**
 * main - the main function to initiate monty
 * @argc: argument count
 * @argv: arguments vector
 * Return: EXIT_SUCCESS, EXIT_FAILURE if fails
 */
int main(int argc, char *argv[])
{
	stack_t *head;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	head = NULL;
	global_ptr = &head;

	tokenizer(argv[1], &head);

	atexit(g_free);
	exit(EXIT_SUCCESS);
}

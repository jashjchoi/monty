#include "monty.h"
/**
* g_free - frees global variable
* Return: void
*/
void g_free(void)
{
	stack_t *to_free;
	stack_t *temp = NULL;

	to_free = *global_ptr;
	while (to_free)
	{
		temp = to_free->next;
		free(to_free);
		to_free = temp;
	}
}

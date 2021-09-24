#include "monty.h"
global_var_t gv;

/**
 * free_buffer - frees the array of strings that
 * holds the command
 */
void free_buffer(void)
{
	free(gv.str);
	fclose(gv.fp);
}

/**
 * free_stack - frees the stack (list)
 * @head: points to the head of the list
 */
void free_stack(stack_t *head)
{
	stack_t *aux;

	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}

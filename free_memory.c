#include "monty.h"

/**
 * free_memory - free's a stach memory
 * @start: points to the memory address of the first node
 */
void free_memory(stack_t **start)
{
	stack_t *p, *aux;

	if (*start)
	{
		p = *start;
		*start = NULL;

		while (p->next)
		{
			aux = p;
			p = p->next;
			free(aux);
		}
		free(p);
	}
}

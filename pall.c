#include "monty.h"

/**
 * pall - prints the values on the stack, from the top.
 * @cmd: command for the variable
 */
void pall(command_t *cmd)
{
	stack_t *h = *cmd->start;

	if (h == NULL)
		return;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

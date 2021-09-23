#include "monty.h"
/**
 * push - adds new node at the beginning of a
 * stack or in queue
 * @cmd: command for the variable
 */
void push(command_t *cmd)
{
	stack_t **h = cmd->start;
	stack_t *new = NULL, *aux = NULL;

	if (*h == NULL)
	{
		printf("L%d: usage: push integer\n", cmd->line_number);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		exit(EXIT_FAILURE);
	if (*cmd->way == 1)
	{
		new->n = cmd->arg;
		new->next = NULL;
		new->prev = NULL;
		if (*h == NULL)
		{
			*h = new;
			return;
		}
		aux = *h;
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = new;
		new->prev = aux;
		return;
	}
	if (*h == NULL)
	{
		new->n = cmd->arg;
		new->next = *h;
		new->prev = NULL;
		*h = new;
		return;
	}
	(*h)->prev = new;
	new->next = *h;
	new->prev = NULL;
	*h = new;
}

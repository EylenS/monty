#include "monty.h"
global_var_t gv;

/**
 * swap - swaps the top two elements of the stack
 * @stack: points to the head of the linked list
 * @ln: line number
 */
void swap(stack_t **stack, unsigned int ln)
{
	stack_t *aux, *p;
	int num;

	aux = *stack;
	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't swap, stack too short", ln);
		free_buffer();
		exit(EXIT_FAILURE);
	}

	if (aux && aux->next)
	{
		p = aux->next;
		num = aux->n;
		aux->n = p->n;
		p->n = num;
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short", ln);
		free_buffer();
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}

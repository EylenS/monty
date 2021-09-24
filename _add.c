#include "monty.h"
global_var_t gv;

/**
 * add - This opcode adds the top two elements of
 * the stack.
 * @stack: points to the head of the linked list
 * @ln: line number
 */
void add(stack_t **stack, unsigned int ln)
{
	stack_t *aux, *p;

	aux = *stack;
	if (!aux || !aux->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	p = aux->next;
	p->n = p->n + aux->n;
	pop(stack, ln);
}

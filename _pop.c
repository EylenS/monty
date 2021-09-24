#include "monty.h"
global_var_t gv;

/**
 * pop - this opcode removes the top element of the stack
 * @stack: points to the head of the linked list
 * @ln: line number
 */
void pop(stack_t **stack, unsigned int ln)
{
	stack_t *aux, *p;

	aux = *stack;
	if (!aux)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", ln);
		exit(EXIT_FAILURE);
	}
	p = aux->next;
	free(aux);
	*stack = p;
	aux = *stack;
	if (aux)
		aux->prev = NULL;
}

#include "monty.h"
global_var_t gv;

/**
 * pint - this opcode prints the value at the
 * top of the stack.
 * @stack: points to the head of the linked list
 * @ln: line number
 */
void pint(stack_t **stack, unsigned int ln)
{
	stack_t *aux;

	aux = *stack;
	if (aux)
		printf("%d\n", aux->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}
}

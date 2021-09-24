#include "monty.h"
global_var_t gv;

/**
 * nop - this opcode doesn’t do anything.
 * @stack: points to the head of the linked list
 * @line_number: line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

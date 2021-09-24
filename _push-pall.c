#include "monty.h"
global_var_t gv;

/**
 * push - this opcode pushes an element to the stack.
 * @stack: points to the head of the linked list
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	(void)line_number;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_buffer();
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	new->n = gv.data;
	new->next = NULL;
	new->prev = NULL;

	if (*stack)
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	*stack = new;
}

/**
 * pall - this opcode prints all values on the stack,
 * starting from the top of the stack
 * @stack: points to the head of the linked list
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;
	(void)line_number;

	aux = *stack;
	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

#include "monty.h"
global_var_t gv;

/**
 * get_opcode - according to the operation asked by the user
 * it'll choose the function to perform it.
 * @stack: points to the head of the linked list
 * @line_number: line number
 * Return: a function pointer to opcode selected
 */
int get_opcode(stack_t **stack, unsigned int line_number)
{
	instruction_t fun[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	int i = 0;

	if (gv.str[0] == '#')
	{
		fun[6].f(stack, line_number);
		return (1);
	}
	while (i != 7)
	{
		if (!(strcmp(fun[i].opcode, gv.str)))
		{
			fun[i].f(stack, line_number);
			break;
		}
		i++;
	}
	if (i == 7)
		return (0);
	return (1);
}

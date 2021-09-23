#include "monty.h"

/**
 * def_opc - evaluate the operation
 * @line: input line to analyze
 * @h: points to the memory address of the first node
 * @f: points to the last node's memory address
 * @way: type of data structure to be operated: queue or stack
 * @l_n: line number to be evaluated
 */
void def_opc(char *line, stack_t **h, stack_t **f, int *way, unsigned int l_n)
{
	command_t cmd;

	cmd.way = way;
	cmd.line_number = l_n;
	cmd.start = h;
	cmd.end = f;

	if (define(line, &cmd))
		exec_fun(&cmd);
}

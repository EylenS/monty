#include "monty.h"

/**
 * exec_fun - runs the function according to cmd in the input
 * @cmd: command passed to run the function
 */
void exec_fun(command_t *cmd)
{
	int idx = 0;

	instruction_t fun[] = {
		{"push", push},
		{"pall", pall},
	    {"pint", pint},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	while (fun[idx].opcode)
	{
		if (strcmp(cmd->p, fun[idx].opcode) == 0)
		{
			fun[idx].f(cmd);
			return;
		}
		idx++;
	}
	printf("L%d: unknown instruction %s\n", cmd->line_number, cmd->p);
	exit(EXIT_FAILURE);
}

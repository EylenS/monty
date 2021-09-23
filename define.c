#include "monty.h"

/**
 * define - analyzes the input line
 * @line: input line to analyze
 * @cmd: argument to define the type of operation (queue or stack)
 * Return: 0 to skip the line, 1 to continue
 */
int define(char *line, command_t *cmd)
{
	unsigned int l_n = cmd->line_number;
	int size;
	char *p, *tokens;
	char delim[] = " \n\t";

	if (line == NULL)
		return (0);
	p = strtok(line, delim);
	if (p == NULL)
		return (0);
	if (strcmp(p, "stack") == 0)
	{
		*cmd->way = 0;
		return (0);
	}
	if (strcmp(p, "queue") == 0)
	{
		*cmd->way = 1;
		return (0);
	}
	if (strcmp(p, "push") == 0)
	{
		tokens = strtok(NULL, delim);
		if (tokens == NULL)
		{
			printf("L%d: usage: push integer", l_n);
			exit(EXIT_FAILURE);
		}
		size = strlen(tokens);
		while (size--)
		{
			if (size == 0)
				break;
			if (tokens[size] < 48 || tokens[size] > 57)
			{
				printf("L%d: usage: push integer", l_n);
				exit(EXIT_FAILURE);
			}
		}
		cmd->arg = atoi(tokens);
		cmd->p = p;
		return (1);
	}
	cmd->p = p;
	return (1);
}

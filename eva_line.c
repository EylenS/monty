#include "monty.h"
global_var_t gv;

/**
 * eva_line - analyzes the line (tokenizes the line)
 * @c: line number
 * @head: points to the head of the list
 * Return: pointer that holds a substring (command)
 */
char *eva_line(unsigned int c, stack_t *head)
{
	int idx = 0;
	char *token = NULL, *tokens = NULL;

	token = strtok(gv.buffer, " \n");
	if (token == NULL)
		return (NULL);
	if (strcmp(token, "push") == 0)
	{
		tokens = strtok(NULL, " \n");
		if (tokens == NULL)
			int_error(c, head);
		while (tokens[idx])
		{
			if (idx == 0 && tokens[idx] == '-')
			{
				idx++;
				continue;
			}
			if (tokens[idx] >= 48 && tokens[idx] <= 57)
			{
				idx++;
				continue;
			}
			else
				int_error(c, head);
		}
		gv.data = atoi(tokens);
	}
	return (token);
}

/**
 * int_error - prints an int error and exit
 * @c: line number
 * @head: points to the head of the list
 */
void int_error(unsigned int c, stack_t *head)
{
	fprintf(stderr, "L%u: usage: push integer\n", c);
	free_buffer();
	free(gv.buffer);
	free_stack(head);
	exit(EXIT_FAILURE);
}

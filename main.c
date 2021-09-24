#include "monty.h"
global_var_t gv;

/**
 * main - reads a monty file (.m) and
 * execute it line by line
 * @argc: argument counter
 * @argv: argument vector
 * Return: on seccess 0
 */
int main(int argc, char **argv)
{
	int check;
	unsigned int count = 0;
	ssize_t lines;
	size_t buff_size = 0;
	stack_t *head = NULL;

	gv.buffer = NULL;
	gv.str = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	gv.fp = fopen(argv[1], "r");
	if (gv.fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	lines = getline(&gv.buffer, &buff_size, gv.fp);
	check_getline(lines);
	while (lines >= 0)
	{
		gv.str = NULL;
		count++;
		gv.str = eva_line(count, head);
		if (gv.str == NULL)
		{
			lines = getline(&gv.buffer, &buff_size, gv.fp);
			continue;
		}
		check = get_opcode(&head, count);
		check_opcode(check, count, head);
		lines = getline(&gv.buffer, &buff_size, gv.fp);
	}
	free_buffer();
	free_stack(head);
	return (0);
}

#include "monty.h"
global_var_t gv;

/**
 * check_getline - check if the file was read. Getline
 * returns the number of characters; if there has been an
 * error it returns -1
 * @lines: number of characters read
 */
void check_getline(ssize_t lines)
{
	if (lines == -1)
	{
		free(gv.buffer);
		fclose(gv.fp);
		exit(0);
	}
}

/**
 * check_opcode - check if the right opcode was found
 * @check: the int is used to check if the opcode was found
 * @c: line number
 * @head: points to the head of the linked list
 */
void check_opcode(int check, unsigned int c, stack_t *head)
{
	if (check == 0)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", c, gv.str);
		free_buffer();
		free_stack(head);
		exit(EXIT_FAILURE);
	}
}

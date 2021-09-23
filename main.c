#include "monty.h"

/**
 * main - Entry point to program execution
 * @argc: contains the number of arguments that have been entered
 * @argv: array of pointers to characters
 * Return: EXIT_SUCCESS, or EXIT_FAILURE on failure
 */
int main(int argc, char **argv)
{
	FILE *fd;
	char *line;
	int way;
	unsigned int line_number;
	size_t size;
	ssize_t read;
	stack_t *start = NULL, *end = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	size = 0;
	way = 1;
	while ((read = getline(&line, &size, fd)) != -1)
	{
		def_opc(line, &start, &end, &way, line_number);
		line_number++;
	}

	fclose(fd);
	free(line);
	free_memory(&start);
	return (EXIT_SUCCESS);
}

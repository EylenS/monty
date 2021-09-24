#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

/* LIBRATRIES */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

/* STRUCTS */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* GLOBAL VARIABLE */
/**
 * struct global_var_s - global variable type structure
 * allows to pass vars across functions
 * @fp: the file to be opend and read
 * @buffer: buffer that holds the command for line
 * @str: array of strings that holds the command
 * @data: an int to use for data in a given node
 */
typedef struct global_var_s
{
	FILE *fp;
	char *buffer;
	char *str;
	int data;
} global_var_t;
extern global_var_t gv;

/* PROTOTYPES */
char *eva_line(unsigned int c, stack_t *head);
void check_getline(ssize_t lines);
int get_opcode(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int ln);
void pop(stack_t **stack, unsigned int ln);
void swap(stack_t **stack, unsigned int ln);
void add(stack_t **stack, unsigned int ln);
void nop(stack_t **stack, unsigned int line_number);
void check_opcode(int check, unsigned int c, stack_t *head);
void int_error(unsigned int c, stack_t *head);
void free_buffer(void);
void free_stack(stack_t *head);

#endif

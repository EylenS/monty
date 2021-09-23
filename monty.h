#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

/* --LIBRARIES-- */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

/* --STRUCTS-- */
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
 * struct command_s - command structure
 * @operation: instruction code (name of operation)
 * @argument: argument for function
 * @type_struct: data structure type: stack or queue
 * @line_number: line number to be evaluated
 * @head: head of the linked list
 * @tail: tail of inked list
 */
typedef struct command_s
{
    char *p;
    int arg;
    int *way;
    unsigned int line_number;
    stack_t **start;
    stack_t **end;
} command_t;

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
	void (*f)(command_t *cmd);
} instruction_t;

/* --PROTOTYPES-- */
void def_opc(char *line, stack_t **h, stack_t **f, int *way, unsigned int l_n);
int define(char *line, command_t *cmd);
void exec_fun(command_t *cmd);
void push(command_t *cmd);
void pall(command_t *cmd);
void free_memory(stack_t **start);

#endif

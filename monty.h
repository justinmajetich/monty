#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/* STRUCTURES */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct allocation_history - tracks and stores allocations
 * @mem_ptr: pointer to allocated memory
 * @next: pointer to next node in list
 *
 * Description: stores a pointer to each allocation, allowing
 * greater organization and more efficient freeing
 */
typedef struct allocation_history
{
	char *mem_ptr;
	struct allocation_history *next;

} mem_list;

/* PROTOTYPES */
void exec_op(char **args);
void (*get_op(char *func_string))(stack_t **head, unsigned int line_number);
void print_error(size_t, char *);
void free_memory(const char *scope);

/* OPCODE PROTOTYPES */
void _push(char **args);
void _pall(stack_t **head, unsigned int line_number);
void _pint(stack_t **head, unsigned int line_number);
void _pop(stack_t **head, unsigned int line_number);

/* EXTERNS */
extern unsigned int line_number; /* input line number */
unsigned int line_number;
extern stack_t *head; /* stack head */
stack_t *head;
extern stack_t *tail; /* end of list */
stack_t *tail;
extern mem_list *misc_mem_head; /* head of misc mem tracker */
mem_list *misc_mem_head;

#endif /* MONTY_H */

#include "monty.h"
/**
 * _stack - change list mode to stack (default)
 * @head: head of stack
 * @line_number: line number of input file
 */
void _stack(stack_t **head, unsigned int line_number)
{
	(void)line_number;
	(void)head;
	list_mode = 0;
}
/**
 * _queue - change list mode to queue
 * @head: head of stack
 * @line_number: line number of input file
 */
void _queue(stack_t **head, unsigned int line_number)
{
	(void)line_number;
	(void)head;
	list_mode = 1;
}

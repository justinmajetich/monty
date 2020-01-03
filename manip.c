#include "monty.h"

/**
 * _pop - removed the top element of the stack
 * @head: pointer to beginning of stack or queue
 * @line_number: the line number at which the opcode is called on
 */

void _pop(stack_t **head, unsigned int line_number)
{
	stack_t *pos = *head, *hold;
	(void)line_number;

	if (*head == NULL)
		print_error(7, NULL);
	hold = pos;
	*head = pos->next;
	if (pos->next)
		pos->next->prev = NULL;
	free(hold);
}
/**
 * swap - swap top two elements of stack
 * @head: top of stack
 * @line_number: line number of input file
 */
void _swap(stack_t **head, unsigned int line_number)
{
	stack_t *a, *b;
	(void)line_number;

	if (node_count(head) < 2)
		print_error(8, NULL);

	a = *head;
	b = a->next;
	a->next = b->next;
	b->next->prev = a;
	b->next = a;
	a->prev = b;
	b->prev = NULL;
	*head = b;
}

/**
 * _nop - doesnt do anything
 * @head: top of stack
 * @line_number: line number of input file
 */

void _nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

	return;
}

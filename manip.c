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
 * _swap - swap top two elements of stack
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
}
/**
 * rotl - rotate stack toward top
 * @head: top of stack
 * @line_number: line number of input file
 */
void _rotl(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *tail = NULL;
	(void)line_number;

	if (node_count(head) > 1) /* if less than 1 nodes, rotation is moot */
	{
		/* move tail pointer into postition */
		locate_tail(&tail);

		/* position temp */
		temp = (*head)->next;

		/* move current head to tail */
		temp->prev = NULL;
		tail->next = *head;
		(*head)->prev = tail;
		(*head)->next = NULL;
		*head = temp; /* assign new head */
	}
}
/**
 * rotr - rotate stack toward bottom
 * @head: top of stack
 * @line_number: line number of input file
 */
void _rotr(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *tail = NULL;
	(void)line_number;

	if (node_count(head) > 1) /* if less than 1 nodes, rotation is moot */
	{
		/* move tail pointer into postition */
		locate_tail(&tail);

		/* position temp */
		temp = tail->prev;

		/* move current tail to head */
		temp->next = NULL;
		tail->next = *head;
		tail->prev = NULL;
		(*head)->prev = tail;
		*head = tail; /* assign new head */
	}
}

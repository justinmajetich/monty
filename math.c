#include "monty.h"
/**
 * _add - add top two elements of stack
 * @head: pointer to beginning of stack or queue
 * @line_number: line number of input file
 */
void _add(stack_t **head, unsigned int line_number)
{
	stack_t *a, *b;
	(void)line_number;

	if (node_count(head) < 2)
		print_error(9, NULL);

	/* point a and b to appropriate nodes */
	a = *head;
	b = a->next;

	b->n = a->n + b->n; /* assign sum to b node */
	b->prev = NULL;
	*head = b; /* adjust head pointer */

	/* free top node */
	free(a);
}

/**
 * _sub - subtracts top two elements of stack
 * @head: pointer to beginning of stack or queue
 * @line_number: line number of input file
 */

void _sub(stack_t **head, unsigned int line_number)
{
	stack_t *a, *b;
	(void)line_number;

	if (node_count(head) < 2)
		print_error(10, NULL);

	/* point a and b to appropriate nodes */
	a = *head;
	b = a->next;

	b->n = b->n - a->n; /* assign sum to b node */
	b->prev = NULL;
	*head = b; /* adjust head pointer */

	/* free top node */
	free(a);
}

/**
 * _div - divides top two elements of stack
 * @head: pointer to beginning of stack or queue
 * @line_number: line number of input file
 */

void _div(stack_t **head, unsigned int line_number)
{
	stack_t *a, *b;
	(void)line_number;

	if (node_count(head) < 2)
		print_error(10, NULL);

	/* point a and b to appropriate nodes */
	a = *head;
	b = a->next;

	if (a->n == 0) /* check for divide by 0 */
		print_error(11, NULL);
	b->n = b->n / a->n; /* assign sum to b node */
	b->prev = NULL;
	*head = b; /* adjust head pointer */

	/* free top node */
	free(a);
}

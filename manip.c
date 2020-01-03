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
		print_error(7, NULL)
	hold = pos;
	*head = pos->next;
	if (pos->next)
		pos->next->prev = NULL;
	free(hold);
}

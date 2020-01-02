#include "monty.h"

/**
 * _pall - prints all values on the stack, starting from the top
 * @args: arguments of line passed in from file
 */

void _pall(stack_t **head, unsigned int line_number)
{
	int i;
	(void)line_number;

	for (i = 0; *head != NULL; i++, *head = (*head)->next)
		printf("%d\n", (*head)->n);
}

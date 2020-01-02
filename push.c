#include "monty.h"

/**
 * _push - pushes an element to the stack
 * @args: arguments of line passed in from file
 */

void _push(char **args)
{
	stack_t *new;

	if (!args[1] || !isdigit(args[1]))
		print_error(5);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		print_error(4);
	new->n = atoi(args[1]);
	new->next = NULL;
	new->prev = NULL;
	if (*head)
	{
		new->next = *head;
		(*head)->prev = new;
		*head = new;
	}
	*head = new;
}

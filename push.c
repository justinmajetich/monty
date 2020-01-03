#include "monty.h"
int is_integer(char *string);
/**
 * _push - pushes an element to the stack
 * @args: arguments of line passed in from file
 */

void _push(char **args)
{
	stack_t *new;

	if (!args[1] || !is_integer(args[1]))
		print_error(5, NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		print_error(4, NULL);
	new->n = atoi(args[1]);
	new->next = NULL;
	new->prev = NULL;
	if (head)
	{
		new->next = head;
		head->prev = new;
		head = new;
	}
	head = new;
}
/**
 * is_integer - determines if string is integer
 * @string: string to check
 *
 * Return: 1 is integer, 0 if not
 */
int is_integer(char *string)
{
	while (*string != '\0')
	{
		if (isdigit(*string) == 0)
			return (0);
		string++;
	}
	return (1);
}

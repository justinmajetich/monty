#include "monty.h"
int is_integer(char *string);
/**
 * _push_stack - pushes an element to top of stack
 * @args: line arguments read from file
 */
void _push_stack(char **args)
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
 * _push_queue - pushes an element to rear of queue
 * @args: line arguments read from file
 */
void _push_queue(char **args)
{
	stack_t *new, *tail = NULL;

	/* check if arguments are valid */
	if (!args[1] || !is_integer(args[1]))
		print_error(5, NULL);

	/* allocate for new node */
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		print_error(4, NULL);

	/* initialize new node */
	new->n = atoi(args[1]);
	new->next = NULL;
	new->prev = NULL;

	if (head)
	{
		locate_tail(&tail); /* position tail pointer */
		tail->next = new;
		new->prev = tail;
	}
	else
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
	int i = 0;

	/* if first char is '-', accept and increment to next char */
	if (string[i] == '-')
		i++;

	while (string[i] != '\0')
	{
		/* if char is not digit, return false */
		if (isdigit(string[i]) == 0)
				return (0);
		i++;
	}
	return (1);
}

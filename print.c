#include "monty.h"

/**
 * _pall - prints all values on the stack, starting from the top
 * @head: pointer to beginning of stack or queue
 * @line_number: the line number at which the opcode is called on
 */

void _pall(stack_t **head, unsigned int line_number)
{
	stack_t *pos = *head;
	int i;
	(void)line_number;

	for (i = 0; pos != NULL; i++, pos = pos->next)
		printf("%d\n", pos->n);
}

/**
 * _pint - prints the value at the top of the stack
 * @head: pointer to beginning of stack or queue
 * @line_number: the line number at which the opcode is called on
 */

void _pint(stack_t **head, unsigned int line_number)
{
	(void)line_number;

	if (*head == NULL)
		print_error(6, NULL);
	printf("%d\n", (*head)->n);
}

/**
 * _pchar - prints the char at the top of the stack, followed by a new line
 * @head: pointer to beginning of stack or queue
 * @line_number: the line number at which the opcode is called on
 */

void _pchar(stack_t **head, unsigned int line_number)
{
	(void)line_number;

	if (*head == NULL)
		print_error(16, NULL);
	else if ((*head)->n < 0 || (*head)->n > 127)
		print_error(15, NULL);
	else
		printf("%c\n", (*head)->n);
}

#include "monty.h"

/**
 * exec_op - Executes opcode by argument input
 * @args: arguments passed as tokens from file
 */

void exec_op(char **args)
{
	if (strcmp(args[0], "push") == 0)
		_push(args);
	else
		(*get_op(args[0]))(&head, line_number);
}

/**
 * get_op - Uses correct op code function
 * @func_string: String name of function
 * Return: pointer to correct function
 */

void (*get_op(char *func_string))(stack_t **head, unsigned int line_number)
{
	int i = 0;

	instruction_t ops[] = {
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"add", _add},
		{NULL, NULL}
	};
	while (ops[i].opcode)
	{
		if (strcmp(func_string, ops[i].opcode) == 0)
			return (ops[i].f);
		i++;
	}
	print_error(3, func_string); /* error, if invalid opcode */
	return (NULL);
}

#include "monty.h"

/**
 * exec_op - Executes opcode by argument input
 * @args: arguments passed as tokens from file
 */

void exec_op(char **args)
{
	stack_t *stack = NULL;

	(*get_op(*args))(&stack, line_number);
	/*line_number++;*/
	/*free(*args);*/
}

/**
 * get_op - Uses correct op code function
 * @func: String name of function
 * Return: pointer to correct function
 */

void (*get_op(char *func_string))(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t ops[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};
	while (ops[i].opcode)
	{
		if (strcmp(func_string, ops[i].opcode) == 0)
			return (ops[i].f);
		i++;
	}
	return (NULL);
}

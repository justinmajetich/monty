#include "monty.h"
void print_error_continued(size_t _errno);
/**
 * print_error - print error messages and exit
 * @_errno: error number
 * @s: string argument
 */
void print_error(size_t _errno, char *s)
{
	if (_errno > 8)
		print_error_continued(_errno);

	switch (_errno)
	{
		case 1: /* monty usage */
			dprintf(2, "USAGE: monty file\n");
			break;
		case 2: /* open error */
			dprintf(2, "Error: Can't open file %s\n", s);
			break;
		case 3: /* invalid opcode */
			dprintf(2, "L%u: unknown instruction %s\n", line_number, s);
			break;
		case 4: /* can't malloc */
			dprintf(2, "Error: malloc failed\n");
			break;
		case 5: /* push usage */
			dprintf(2, "L%u: usage: push integer\n", line_number);
			break;
		case 6: /* pint fail */
			dprintf(2, "L%u: can't pint, stack empty\n", line_number);
			break;
		case 7: /* pop fail */
			dprintf(2, "L%u: can't pop an empty stack\n", line_number);
			break;
		case 8: /* swap fail */
			dprintf(2, "L%u: can't swap, stack too short\n", line_number);
			break;
	}
	free_memory("all");
	fclose(input_file);
	exit(EXIT_FAILURE);
}
/**
 * print_error_continued - print error messages and exit
 * @_errno: error number
 */
void print_error_continued(size_t _errno)
{
	switch (_errno)
	{

		case 9: /* add fail */
			dprintf(2, "L%u: can't add, stack too short\n", line_number);
			break;
		case 10: /* sub fail */
			dprintf(2, "L%u: can't sub, stack too short\n", line_number);
			break;
		case 11: /* div fail */
			dprintf(2, "L%u: can't div, stack too short\n", line_number);
			break;
		case 12: /* div by zero */
			dprintf(2, "L%u: division by zero\n", line_number);
			break;
		case 13: /* mul usage */
			dprintf(2, "L%u: can't mul, stack too short\n", line_number);
			break;
		case 14: /* modulus fail */
			dprintf(2, "L%u: can't mod, stack too short\n", line_number);
			break;
		case 15: /* pchar usage */
			dprintf(2, "L%u: can't pchar, value out of range\n", line_number);
			break;
		case 16: /* pchar fail */
			dprintf(2, "L%u: can't pchar, stack empty\n", line_number);
			break;
	}
	free_memory("all");
	fclose(input_file);
	exit(EXIT_FAILURE);
}

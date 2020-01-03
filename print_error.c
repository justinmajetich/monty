#include "monty.h"
/**
 * print_error - print error messages and exit
 * @_errno: error number
 * @s: string argument
 */
void print_error(size_t _errno, char *s)
{
	switch (_errno)
	{
		case 1: /* monty usage */
			dprintf(2, "USAGE: monty file\n");
		case 2: /* open error */
			dprintf(2, "Error: Can't open file %s\n", s);
		case 3: /* invalid opcode */
			dprintf(2, "L%u: unknown instruction %s\n", line_num, s);
		case 4: /* can't malloc */
			dprintf(2, "Error: malloc failed");
		case 5: /* push usage */
			dprintf(2, "L%u: usage: push integer", line_num);
		case 6: /* pint fail */
			dprintf(2, "L%u: can't pint, stack empty", line_num);
		case 7: /* pop fail */
			dprintf(2, "L%u: can't pop an empty stack", line_num);
		case 8: /* swap fail */
			dprintf(2, "L%u: can't swap, stack too short", line_num);
		case 9: /* add fail */
			dprintf(2, "L%u: can't add, stack too short", line_num);
		case 10: /* sub fail */
			dprintf(2, "L%u: can't sub, stack too short", line_num);
		case 11: /* div fail */
			dprintf(2, "L%u: can't div, stack too short", line_num);
		case 12: /* div by zero */
			dprintf(2, "L%u: division by zero", line_num);
		case 13: /* mul usage */
			dprintf(2, "L%u: can't mul, stack too short", line_num);
		case 14: /* modulus fail */
			dprintf(2, "L%u: can't mod, stack too short", line_num);
		case 15: /* pchar usage */
			dprintf(2, "L%u: can't pchar, value out of range", line_num);
		case 16: /* pchar fail */
			dprintf(2, "L%u: can't pchar, stack empty", line_num);
	}
	free_memory("all");
	exit(EXIT_FAILURE);
}

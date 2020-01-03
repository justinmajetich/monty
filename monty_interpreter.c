#include "monty.h"

int main(int argc, char **argv)
{
	unsigned int line_num = 1;
	size_t line_size = 0;
	ssize_t read = 0;
	char *line = NULL;
	char **tokens = NULL;
	FILE *input_file = NULL;

	if (argc != 2)
		print_error(1, NULL); /* monty usage error */

	input_file = fopen(argv[1], "r"); /* open file */
	if (!input_file)
		print_error(2, argv[1]); /* open failed */

	while (line_num++) /* increment line number with iterations */
	{
		/* retrieve line from input */
		read = getline(&line, &line_size, input_file);
		if (read == -1)
			break;

		tokens = malloc(sizeof(char *) * 2);
		if (!tokens)
			print_error(4, NULL);

		tokens[0] = strtok(line, " "); /* tokenize opcode */
		tokens[1] = strtok(NULL, " "); /* tokenize arg */

		exec_op(tokens); /* pass args to executor */

		free_memory("misc"); /* free lines and tokens */
	}
	free_memory("all");
	return (0);
}

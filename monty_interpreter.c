#include "monty.h"
/**
 * main - interpret monty opcode
 * @argc: number of arguments passed to program
 * @argv: string arguments passed to program
 *
 * Return: 0 on success; exit with error code on failure
 */
int main(int argc, char **argv)
{
	size_t line_size = 0;
	ssize_t read = 0;
	char *line = NULL;
	char **tokens = NULL;

	if (argc != 2)
		print_error(1, NULL); /* monty usage error */

	input_file = fopen(argv[1], "r"); /* open file */
	if (!input_file)
		print_error(2, argv[1]); /* open failed */

	list_mode = 0; /* set list mode to default (stack) */
	line_number = 1;
	while (1) /* increment line number with iterations */
	{
		/* retrieve line from input */
		read = getline(&line, &line_size, input_file);
		add_mem_list(line);
		if (read == -1)
			break;

		tokens = malloc(sizeof(char *) * 2);
		if (!tokens)
			print_error(4, NULL);
		add_mem_list((char *)tokens);
		tokens[0] = strtok(line, " \t\n"); /* tokenize opcode */
		tokens[1] = strtok(NULL, " \t\n"); /* tokenize arg */
		if (tokens[0]) /* guard against empty line input */
			exec_op(tokens); /* pass args to executor */

		free_memory("misc"); /* free lines and tokens */
		line = NULL;
		tokens = NULL;
		line_number++;
	}
	fclose(input_file);
	free_memory("all");
	return (EXIT_SUCCESS);
}

#include "monty.h"

/**
 * jay_main - Monty code interpreter
 * @jay_argc: number of arguments
 * @jay_argv: Monty file location
 * Return: 0 on success
 */

int jay_main(int jay_argc, char *jay_argv[])
{

	bus_t jay_bus = {0}; /* Initialize all members to 0 or NULL */
	char *jay_content;
	FILE *jay_file;
	size_t jay_size = 0;
	ssize_t jay_read_line = 1;
	stack_t *jay_stack = NULL;
	unsigned int jay_counter = 0;

	if (jay_argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	jay_file = fopen(jay_argv[1], "r");
	jay_bus.file = jay_file;
	if (!jay_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", jay_argv[1]);
		exit(EXIT_FAILURE);
	}
	while (jay_read_line > 0)
	{
		jay_content = NULL;
		jay_read_line = getline(&jay_content, &jay_size, jay_file);
		jay_bus.content = jay_content;
		jay_counter++;
		if (jay_read_line > 0)
		{
			execute(jay_content, &jay_stack, jay_counter, jay_file);
		}
		free(jay_content);
	}
	free_stack(jay_stack);
	fclose(jay_file);
	return (0);
}

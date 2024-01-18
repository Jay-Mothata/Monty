#include "monty.h"

/**
 * jay_execute - executes the opcode
 * @jay_content: line content
 * @jay_stack: head linked list - stack
 * @jay_counter: line_counter
 * @jay_file: pointer to monty file
 * Return: No return value
 */

int jay_execute(char *jay_content, stack_t **jay_stack, unsigned int jay_counter, FILE *jay_file)
{
	instruction_t jay_opst[] = {
		{"push", jay_push}, {"pall", jay_pall}, {"pint", jay_pint},
		{"pop", jay_pop}, {"swap", jay_swap}, {"add", jay_add},
		{"nop", jay_nop}, {"sub", jay_sub}, {"div", jay_div},
		{"mul", jay_mul}, {"mod", jay_mod}, {"pchar", jay_pchar},
		{"pstr", jay_pstr}, {"rotl", rotl}, {"rotr", rotr},
		{"queue", jay_queue}, {"stack", jay_stack},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *jay_op;

	jay_op = strtok(jay_content, " \n\t");
	if (jay_op && jay_op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (jay_opst[i].opcode && jay_op)
	{
		if (strcmp(jay_op, jay_opst[i].opcode) == 0)
		{
			jay_opst[i].f(jay_stack, jay_counter);
			return (0);
		}
		i++;
	}
	if (jay_op && jay_opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", jay_counter, jay_op);
		fclose(jay_file);
		free(jay_content);
		free_stack(*jay_stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}

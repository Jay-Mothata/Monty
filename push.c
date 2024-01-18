#include "monty.h"

/**
 * jay_push - Adds a node to the stack
 * @jay_head: Pointer to the stack head
 * @jay_counter: Line number
 *
 */
void jay_push(stack_t **jay_head, unsigned int jay_counter)
{
	int jay_n, jay_j = 0, jay_flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			jay_j++;
		for (; bus.arg[jay_j] != '\0'; jay_j++)
		{
			if (bus.arg[jay_j] > 57 || bus.arg[jay_j] < 48)
				jay_flag = 1;
		}
		if (jay_flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", jay_counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*jay_head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", jay_counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*jay_head);
		exit(EXIT_FAILURE);
	}

	jay_n = atoi(bus.arg);
	if (bus.lifi == 0)
		jay_addnode(jay_head, jay_n);
	else
		jay_addqueue(jay_head, jay_n);
}

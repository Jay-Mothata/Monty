#include "monty.h"

/**
 * jay_pint - prints the top element of the stack
 * @jay_head: pointer to the stack head
 * @jay_counter: line number
 * Return: No return value
 */

void jay_pint(stack_t **jay_head, unsigned int jay_counter)
{
	if (*jay_head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", jay_counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*jay_head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*jay_head)->n);
}

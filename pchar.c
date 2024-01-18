#include "monty.h"

/**
 * jay_pchar - prints the char at the top of the stack,
 * followed by a new line
 * @jay_head: stack head
 * @jay_counter: line_number
 * Return: No return value
 */

void jay_pchar(stack_t **jay_head, unsigned int jay_counter)
{
	stack_t *jay_h;

	jay_h = *jay_head;
	if (!jay_h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", jay_counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*jay_head);
		exit(EXIT_FAILURE);
	}
	if (jay_h->n > 127 || jay_h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", jay_counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*jay_head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", jay_h->n);
}

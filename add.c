#include "monty.h"

/**
 * jay_add - adds the top two elements of the stack.
 * @jay_head: stack head
 * @jay_counter: line_number
 * Return: No return value
 */

void jay_add(stack_t **jay_head, unsigned int jay_counter)
{
	stack_t *jay_h;
	int jay_len = 0, jay_aux;

	jay_h = *jay_head;
	while (jay_h)
	{
		jay_h = jay_h->next;
		jay_len++;
	}
	if (jay_len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", jay_counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*jay_head);
		exit(EXIT_FAILURE);
	}
	jay_h = *jay_head;
	jay_aux = jay_h->n + jay_h->next->n;
	jay_h->next->n = jay_aux;
	*jay_head = jay_h->next;
	free(jay_h);
}

#include "monty.h"

/**
 * jay_mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @jay_head: stack head
 * @jay_counter: line_number
 * Return: No return value
 */

void jay_mod(stack_t **jay_head, unsigned int jay_counter)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", jay_counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*jay_head);
		exit(EXIT_FAILURE);
	}
	jay_h = *jay_head;
	if (jay_h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", jay_counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*jay_head);
		exit(EXIT_FAILURE);
	}
	jay_aux = jay_h->next->n % jay_h->n;
	jay_h->next->n = jay_aux;
	*jay_head = jay_h->next;
	free(jay_h);
}

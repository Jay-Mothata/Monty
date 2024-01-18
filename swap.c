#include "monty.h"

/**
 * jay_swap - swaps the top two elements of the stack.
 * @jay_head: pointer to the stack head
 * @jay_counter: line number
 * Return: No return value
 */

void jay_swap(stack_t **jay_head, unsigned int jay_counter)
{
	stack_t *jay_temp;
	int jay_len = 0, jay_aux;

	jay_temp = *jay_head;
	while (jay_temp)
	{
		jay_temp = jay_temp->next;
		jay_len++;
	}
	if (jay_len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", jay_counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*jay_head);
		exit(EXIT_FAILURE);
	}
	jay_temp = *jay_head;
	jay_aux = jay_temp->n;
	jay_temp->n = jay_temp->next->n;
	jay_temp->next->n = jay_aux;
}

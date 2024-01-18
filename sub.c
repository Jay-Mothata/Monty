#include "monty.h"

/**
 * jay_sub - subtraction
 * @jay_head: stack head
 * @jay_counter: line_number
 * Return: No return value
 */

void jay_sub(stack_t **jay_head, unsigned int jay_counter)
{
	stack_t *jay_aux;
	int jay_result, jay_nodes;

	jay_aux = *jay_head;
	for (jay_nodes = 0; jay_aux != NULL; jay_nodes++)
		jay_aux = jay_aux->next;

	if (jay_nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", jay_counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*jay_head);
		exit(EXIT_FAILURE);
	}

	jay_aux = *jay_head;
	jay_result = jay_aux->next->n - jay_aux->n;
	jay_aux->next->n = jay_result;
	*jay_head = jay_aux->next;
	free(jay_aux);
}

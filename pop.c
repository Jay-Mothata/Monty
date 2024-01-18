#include "monty.h"

/**
 * jay_pop - removes the top element of the stack
 * @jay_head: pointer to the stack head
 * @jay_counter: line number
 * Return: No return value
 */

void jay_pop(stack_t **jay_head, unsigned int jay_counter)
{
	stack_t *jay_temp;

	if (*jay_head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", jay_counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*jay_head);
		exit(EXIT_FAILURE);
	}

	jay_temp = *jay_head;
	*jay_head = jay_temp->next;
	free(jay_temp);
}

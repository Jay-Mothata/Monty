#include "monty.h"

/**
 * jay_free_stack - frees a doubly linked list
 * @jay_head: head of the stack
 */

void jay_free_stack(stack_t *jay_head)
{
	stack_t *jay_aux;

	jay_aux = jay_head;
	while (jay_head)
	{
		jay_aux = jay_head->next;
		free(jay_head);
		jay_head = jay_aux;
	}
}

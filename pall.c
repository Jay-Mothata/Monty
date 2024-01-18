#include "monty.h"

/**
 * jay_pall - Prints the stack
 * @jay_head: Pointer to the stack head
 * @jay_counter: Not used
 *
 * Description: This function prints the elements of the stack.
 * It traverses the stack and prints each element on a new line.
 */

void jay_pall(stack_t **jay_head, unsigned int jay_counter)
{
	stack_t *jay_h;
	(void)jay_counter;

	jay_h = *jay_head;
	if (jay_h == NULL)
		return;
	while (jay_h)
	{
		printf("%d\n", jay_h->n);
		jay_h = jay_h->next;
	}
}

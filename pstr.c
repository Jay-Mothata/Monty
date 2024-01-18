#include "monty.h"

/**
 * jay_pstr - prints the string starting at the top of the stack,
 * followed by a new line
 * @jay_head: stack head
 * @jay_counter: line_number
 * Return: No return value
 */

void jay_pstr(stack_t **jay_head, unsigned int jay_counter)
{
	stack_t *jay_h;
	(void)jay_counter;

	jay_h = *jay_head;
	while (jay_h)
	{
		if (jay_h->n > 127 || jay_h->n <= 0)
		{
			break;
		}
		printf("%c", jay_h->n);
		jay_h = jay_h->next;
	}
	printf("\n");
}

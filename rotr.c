#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @jay_head: stack head
 * @jay_counter: line_number
 * Return: no return
 */

void rotr(stack_t **jay_head, __attribute__((unused)) unsigned int jay_counter)
{
	stack_t *jay_copy;

	jay_copy = *jay_head;
	if (*jay_head == NULL || (*jay_head)->next == NULL)
	{
		return;
	}
	while (jay_copy->next)
	{
		jay_copy = jay_copy->next;
	}
	jay_copy->next = *jay_head;
	jay_copy->prev->next = NULL;
	jay_copy->prev = NULL;
	(*jay_head)->prev = jay_copy;
	(*jay_head) = jay_copy;
}


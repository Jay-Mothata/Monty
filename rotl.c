#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @jay_head: stack head
 * @jay_counter: line_number
 * Return: no return
 */

void rotl(stack_t **jay_head, __attribute__((unused)) unsigned int jay_counter)
{
	stack_t *jay_tmp = *jay_head, *jay_aux;

	if (*jay_head == NULL || (*jay_head)->next == NULL)
	{
		return;
	}
	jay_aux = (*jay_head)->next;
	jay_aux->prev = NULL;
	while (jay_tmp->next != NULL)
	{
		jay_tmp = jay_tmp->next;
	}
	jay_tmp->next = *jay_head;
	(*jay_head)->next = NULL;
	(*jay_head)->prev = jay_tmp;
	(*jay_head) = jay_aux;
}

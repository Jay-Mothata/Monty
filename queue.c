#include "monty.h"

/**
 * jay_queue - prints the top
 * @jay_head: stack head
 * @jay_counter: line_number
 * Return: no return
 */

void jay_queue(stack_t **jay_head, unsigned int jay_counter)
{
	(void)jay_head;
	(void)jay_counter;
	bus.lifi = 1;
}

/**
 * jay_addqueue - add node to the tail stack
 * @jay_n: new_value
 * @jay_head: head of the stack
 * Return: no return
 */

void jay_addqueue(stack_t **jay_head, int jay_n)
{
	stack_t *jay_new_node, *jay_aux;

	jay_aux = *jay_head;
	jay_new_node = malloc(sizeof(stack_t));
	if (jay_new_node == NULL)
	{
		printf("Error\n");
	}
	jay_new_node->n = jay_n;
	jay_new_node->next = NULL;
	if (jay_aux)
	{
		while (jay_aux->next)
			jay_aux = jay_aux->next;
	}
	if (!jay_aux)
	{
		*jay_head = jay_new_node;
		jay_new_node->prev = NULL;
	}
	else
	{
		jay_aux->next = jay_new_node;
		jay_new_node->prev = jay_aux;
	}
}

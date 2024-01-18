#include "monty.h"

/**
 * jay_addnode - add node to the head stack
 * @jay_head: head of the stack
 * @jay_n: new_value
 * Return: no return
 */

void jay_addnode(stack_t **jay_head, int jay_n)
{
	stack_t *jay_new_node, *jay_aux;

	jay_aux = *jay_head;
	jay_new_node = malloc(sizeof(stack_t));
	if (jay_new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (jay_aux)
		jay_aux->prev = jay_new_node;
	jay_new_node->n = jay_n;
	jay_new_node->next = *jay_head;
	jay_new_node->prev = NULL;
	*jay_head = jay_new_node;
}

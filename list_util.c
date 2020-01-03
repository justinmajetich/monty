#include "monty.h"
/**
 * node_count - count list elements
 * @h: head of list
 *
 * Return: number of elements in list
 */
size_t node_count(stack_t **h)
{
	size_t node_cnt = 0;
	stack_t *temp;

	temp = h;
	while (temp)
	{
		node_cnt++;
		temp = temp->next;
	}
	return (node_cnt);
}

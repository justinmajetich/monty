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

	temp = *h;
	while (temp)
	{
		node_cnt++;
		temp = temp->next;
	}
	return (node_cnt);
}
/**
 * locate_tail - move pointer to tail
 * @tail: pointer to point to tail
 */
void locate_tail(stack_t **tail)
{
	*tail = head; /* initialize tail at head of list */
	while ((*tail)->next) /* loop till tail points at last node */
		(*tail) = (*tail)->next;
}

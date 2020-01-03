#include "monty.h"
void free_mem_list(mem_list **h);
void free_stack_t(stack_t **h);
/**
 * free_memory - free memory allocations
 * @scope: specifies which lists to free
 */
void free_memory(const char *scope)
{
	if (strcmp(scope, "misc") == 0)
		free_mem_list(&misc_mem_head);
	
	if (strcmp(scope, "all") == 0)
	{
		free_mem_list(&misc_mem_head);
		free_stack_t(&head);
	}
}
/**
 * free_mem_list - free misc mem list and set head to NULL
 * @h: pointer to struct to free
 */
void free_mem_list(mem_list **h)
{
	mem_list *temp;

	if (h)
		while (*h)
		{
			temp = *h; /* assign temp pointer to current head */
			*h = (*h)->next; /* move head forward */
			if (temp->mem_ptr) /* pointer to allocation is not NULL */
				free(temp->mem_ptr); /* free allocation */
			free(temp); /* free node */
		}
}
/**
 * free_stack_t - free stack and set head to NULL
 * @h: pointer to struct to free
 */
void free_stack_t(stack_t **h)
{
	stack_t *temp;

	if (h)
		while (*h)
		{
			temp = *h; /* assign temp pointer to current head */
			*h = (*h)->next; /* move head forward */
			free(temp); /* free node */
		}
}

#include "monty.h"
/**
 * add_mem_list - add node to head of misc memory list
 * @ptr: pointer to add to list
 */
void add_mem_list(char *ptr)
{
	mem_list *new; /* ptr to new node */

	new = malloc(sizeof(mem_list));
	if (!new)
		print_error(4, NULL);

	/* initialize new node */
	new->mem_ptr = ptr;
	new->next = misc_mem_head;
	misc_mem_head = new;
}
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

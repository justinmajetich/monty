#include "monty.h"

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
		free_mem_list(&head);
	}
}
/**
 * free_mem_list - free list and sety head to NULL
 * @head: pointer to struct to free
 */
void free_mem_list(mem_list **head)
{
	mem_list *temp;

	if (head)
	{
		while (*head)
		{
			temp = *head; /* assign temp pointer to current head */
			*head = (*head)->next; /* move head forward */
			if (temp->mem_ptr) /* pointer to allocation is not NULL */
				free(temp->mem_ptr); /* free allocation */
			free(temp); /* free node */
		}
		*head = NULL; /* restore head pointer to NULL */
	}
}

#include "monty.h"

/**
delete_head - deletes top of linked list
* @head: top of linked list
*/

void delete_head(stack_t **stack)
{
	stack_t *tmp = *stack, *top = NULL;

	top = tmp;
	if ((*tmp).next != NULL)
		(*tmp).next->prev = NULL;
	*stack = (*tmp).next;
	free(top);
}

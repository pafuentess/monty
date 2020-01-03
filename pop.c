#include "monty.h"


void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void) line_number;

	if (stack == NULL || *stack == NULL)
		 exit(EXIT_FAILURE);

	tmp = *stack;
	*stack = tmp->next;
	if (tmp->next != NULL)
	{
		tmp->next->prev = NULL;
	}
	free(tmp);
}

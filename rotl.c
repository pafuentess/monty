#include "monty.h"

/**
* rotl - rotates the stack to the top.
*@stack: head of a linked list
*@line_number: line number
*/

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int number;
	(void) line_number;

	if (*stack == NULL)
		return;
	tmp = *stack;
	if (tmp->next == NULL)
		return;
	number = tmp->n;
	while (tmp->next != NULL)
	{
		tmp->n = tmp->next->n;
		tmp = tmp->next;
	}
	tmp->n = number;
}

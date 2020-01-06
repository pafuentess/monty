#include "monty.h"

/**
* rotl - rotates the stack to the top.
*@stack: head of a linked list
*@line_number: line number
*/

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp1 = *stack;
	(void) line_number;

	if (*stack == NULL)
		return;
	while (tmp1->next != NULL)
	{
		tmp1 = tmp1->next;
	}
	tmp1->next = *stack;
	(*stack)->prev = tmp1;
	tmp1 = (*stack)->next;
	(*stack)->next = NULL;
	*stack = tmp1;
	(*stack)->prev = NULL;
}

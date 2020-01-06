#include "monty.h"

/**
* rotl - rotates the stack to the top.
*@stack: head of a linked list
*@line_number: line number
*/

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp1 = *stack, *tmp2 = *stack, *tmp3 = NULL;
	(void) line_number;

	if (*stack == NULL)
		return;
	tmp3 = tmp1->next;
	while (tmp1->next != NULL)
	{
		tmp1 = tmp1->next;
	}
	tmp1->next = *stack;
	tmp2->prev = tmp1;
	tmp2->next = NULL;
	*stack = tmp3;
	(*stack)->prev = NULL;

}

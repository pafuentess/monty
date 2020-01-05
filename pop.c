#include "monty.h"
/**
*pop- The opcode pop removes the top element of the stack
*@stack: head of a linked list
*@line_number: line number
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void) line_number;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = tmp->next;
	if (tmp->next != NULL)
	{
		tmp->next->prev = NULL;
	}
	free(tmp);
}

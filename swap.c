#include "monty.h"
/**
*swap- The opcode swap swaps the top two elements of the stack
*@stack: head of a linked list
*@line_number: line number
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *tmp1, *tmp2;
	int a = 0, b = 0;
	int i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp1 = *stack;
	tmp2 = tmp1->next;
	a = tmp1->n;
	b = tmp2->n;
	tmp1->n = b;
	tmp2->n = a;
}

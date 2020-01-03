#include "monty.h"


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
	if (i >= 2)
	{	
		tmp1 = *stack;
		tmp2 = tmp1->next;
		a = tmp1->n;
		b = tmp2->n;
		tmp1->n = b;
		tmp2->n = a;
	}
	else
	{
		fprintf(stderr, "L%d: cant't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

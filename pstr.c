#include "monty.h"

/**
*pstr- prints the string starting at the top of the stack
*@stack: head of a linked list
*@line_number: line number
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void) line_number;

	tmp = *stack;
	while (tmp)
	{
		if ((tmp->n >= 0 && tmp->n <=  127))
		{
			fprintf(stdout, "%c", tmp->n);
		}
		tmp = tmp->next;
		if (tmp == *stack)
			return;
	}
	fprintf(stdout, "\n");
}

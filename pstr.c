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
	if (tmp != NULL)
	{
		while (tmp != NULL && tmp->n != 0)
		{
			if ((tmp->n >= 0 && tmp->n <=  127))
			{
				fprintf(stdout, "%c", tmp->n);
			}
			else
				break;
			tmp = tmp->next;
	}
	fprintf(stdout, "\n");
}

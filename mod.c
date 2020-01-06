#include "monty.h"
/**
*mod_fun- computes the rest of the division of the 2nd top element to the top
*@stack: head of a linked list
*@line_number: line number
*/
void mod_fun(stack_t **stack, unsigned int line_number)
{
	int len = 0, a = 0, b = 0;
	stack_t *temp, *temp1, *temp2;

	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if  (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp1 = *stack;
		temp2 = temp1->next;
		a = temp1->n;
		b = temp2->n;
		if (a == 0)
		{
			fprintf(stderr, "L%d: division by zero", line_number);
			exit(EXIT_FAILURE);
		}
		else
		{
			temp2->n = b % a;
			free(temp1);
			*stack = temp2;
			(*stack)->prev = NULL;
		}
	}
}

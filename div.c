#include "monty.h"
/**
*div_fun- divides the second top element of the stack by the top element
*@stack: head of a linked list
*@line_number: line number
*/
void div_fun(stack_t **stack, unsigned int line_number)
{
	int len = 0, a = 0, b = 0;
	stack_t *temp, *temp1, *temp2;
	
	if (stack == NULL)
		return;
	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if  (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp1 = *stack;
	temp2 = temp1->next;
	a = temp1->n;
	b = temp2->n;
	if (a == 0)
	{
		fprintf(stderr, "L%d: division by zero", line_number);
		exit(EXIT_FAILURE);
	}
	temp2->n = b / a;
	*stack = temp2;
	free(temp1);
	temp2->prev = NULL;
}


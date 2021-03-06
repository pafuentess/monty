#include "monty.h"
/**
*mult- multiplies the second top element of the stack with the top element
*@stack: head of a linked list
*@line_number: line number
*/
void mult(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp1 = *stack;
		temp2 = temp1->next;
		a = temp1->n;
		b = temp2->n;
		temp2->n = b * a;
		free(temp1);
		*stack = temp2;
		(*stack)->prev = NULL;
	}
}

#include "monty.h"
/**
*div_fun- divides the second top element of the stack by the top element
*@stack: head of a linked list
*@line_number: line number
*/
void div_fun(stack_t **stack, unsigned int line_number)
{
	int len = 0, a = 0;
	stack_t *temp;

	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if  ((len < 2) || (*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	pop(stack, line_number);
	if (a == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->n = (*stack)->n / a;
}

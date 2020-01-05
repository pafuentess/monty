#include "monty.h"
/**
*add- The opcode add adds the top two elemetns of the stack
*@stack: head of a linked list
*@line_number: line number
*/
void add(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp1 = *stack;
		temp2 = temp1->next;
		a = temp1->n;
		b = temp2->n;
		temp2->n = a + b;
		free(temp1);
		*stack = temp2;
		(*stack)->prev = NULL;
	}
}

#include "monty.h"
/**
*rotr-The opcode rotr rotates the stack to the bottom
*@stack: head of a linked list
*@line_number: line number
*/
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *Prev = NULL;
	stack_t *Next = NULL;
	unsigned int i = 0;
	(void) line_number;

	while ((*stack)->next)
	{
		Next = (*stack)->next;
		(*stack)->next = Prev;
		Prev = *stack;
		*stack = Next;
	}
	*stack = Prev;
	while (*stack)
	{
		fprintf(stdout, "%d\n", (*stack)->n);
		*stack = (*stack)->next;
		i++;
	}
}

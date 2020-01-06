#include "monty.h"
/**
*rotr-The opcode rotr rotates the stack to the bottom
*@stack: head of a linked list
*@line_number: line number
*/
void rotr(stack_t **stack, unsigned int line_number)
{

	int a = 0;
	stack_t *temp;
	(void) line_number;

	if (*stack == NULL)
		return;
	
	temp = *stack;
	if (temp->next == NULL)
		return;

	while (temp->next)
	{
		temp = temp->next;
	}
	a = temp->n;
	while (temp->prev)
	{
		temp->n = temp->prev->n;
		temp = temp->prev;
	}
	temp->n = a;
}

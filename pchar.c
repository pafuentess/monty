#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
*pchar- prints the char at the top of the stack, followed by a new line
*@stack: head of a linked list
*@line_number: line number
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp2;

	tmp2 = *stack;
	if (tmp2 != NULL)
	{
		if (tmp2->n >= 0 && tmp2->n <= 127)
			fprintf(stdout, "%c\n", tmp2->n);
		else
		{
			fprintf(stderr, "L%d: can't pchar, value out of range", line_number);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);

	}
}

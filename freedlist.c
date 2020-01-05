#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"

/**
* free_stack - free linked list
* @stack: head of linked list
*/

void free_stack(stack_t **stack)
{
	stack_t *tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

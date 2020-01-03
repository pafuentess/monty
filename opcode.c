#include "monty.h"


void push(stack_t **stack, unsigned int line_number)
{	
	stack_t *new_node;
	(void) line_number;
/*	printf("paula\n");*/
	new_node = malloc(sizeof(stack_t));
	
	if (new_node == NULL)
		 exit(EXIT_FAILURE);
/*	printf("fuentes\n");*/
	new_node->prev = NULL;
	new_node->next = *stack;
	*stack = new_node;
	new_node->n = number;

	if (new_node->next != NULL)
		(new_node->next)->prev = new_node;
/*	printf("paulita\n");*/
}

void pall(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	int i;
	stack_t *tmp;
	
/*	printf("entre");*/
	tmp = *stack;
	i = 0;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
		i++;
	}
}

#include "monty.h"

/**
*check- function to check words
*@buffer: buffer
*@header: double pointer stack_t
*@line_number: line number
*/
void check(char *buffer, stack_t **header, unsigned int line_number)
{
	instruction_t op[] = {{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add}, {"nop", nop}, {"sub", sub},
		{NULL, NULL}};
	int i = 0;

	while (op[i].opcode != NULL)
	{
		if (strcmp(buffer, op[i].opcode) == 0)
		{
			(op[i].f)(header, line_number);
			break;
		}
		i++;
	}
	if (op[i].opcode == NULL)
	{
/*		free(token);*/
		fprintf(stderr, "L%d: unknown instructions %s\n", line_number, buffer);
		exit(EXIT_FAILURE); }
}

/**
*check_number- check if num is number
*@num: char  pointer
*@line_number: line number
*Return: 1 if num is number or -1 if num is not a number
*/
int check_number(char *num, unsigned int line_number)
{
	int i = 0;

	while (num[i])
	{
		if (num[i] < 47 || num[i] > 58)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (1);
}
/**
*count_ar- count
*@token: double pointer
*Return: integer
*/
int count_ar(char **token)
{
	int i = 0;

	while (token[i])
		i++;
	return (i);
}

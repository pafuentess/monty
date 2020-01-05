#include "monty.h"

/**
*main - Execute Monty language
*@argc: Number of arguments
*@argv: arguments
*Return: Integer 0
*/

int main(int argc, char **argv)
{
	char *buff = NULL;
	char *token = NULL;
	FILE *fd;
	size_t size;
	stack_t *stack;
	unsigned int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stack = NULL;
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buff, &size, fd) != -1)
	{
		token = strtok(buff, "\n\t\r ");
		if (token != NULL || token[0] == '#')
			check(token, &stack, line_number);
		line_number++;

	}
	free_stack(&stack);
	free(buff);
	fclose(fd);
	exit(EXIT_SUCCESS);
}

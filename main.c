#include "monty.h"

easy_t global = {0, NULL};

/**
*main - Execute Monty language
*@argc: Number of arguments
*@argv: arguments
*Return: Integer 0
*/
int main(int argc, char **argv)
{
	char *buff = malloc(1024 * sizeof(char *));
	char *token = malloc(1024 * sizeof(char *));
	FILE *fd;
	size_t size;
	unsigned int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buff, &size, fd) != -1)
	{
		token = strtok(buff, "\n\t\r");
		check(token, (&global.stack), line_number);
		line_number++;
	}
/*	free(buff);*/
	free(token);
	free_dlistint(global.stack);
	fclose(fd);
	exit(EXIT_SUCCESS);
}

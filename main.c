#include "monty.h"

easy_t global = {0, NULL};

int main(int argc, char **argv)
{
        char *buff = malloc(1024 *sizeof(char *)), *token = malloc(1024 * sizeof(char *));
	FILE *fd;
	size_t size;
	unsigned int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
        while (getline(&buff, &size, fd) != -1)
	{
		token = strtok(buff, "\n\t\r");
		check(token, (&global.stack), line_number);
		line_number++;
 	}
        return (0);
	exit (EXIT_SUCCESS);
}

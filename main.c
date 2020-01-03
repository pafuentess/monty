#include "monty.h"

int number = 0;

int main(int argc, char **argv)
{
        char *buff, **token;
	stack_t *stack;
        int i = 0;
	unsigned int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stack = NULL;
        buff = read_textfile(argv[1]);
        token = tokenizar(buff, "\n");
        while (token[i])
	{
                check(token[i], &stack, line_number);
                i++;
		line_number++;
        }
        return (0);
}


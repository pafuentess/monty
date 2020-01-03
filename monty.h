#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct instruction_s
{
        char *opcode;
//	void (*f)(int n);
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* global variable */
extern int number;

char *read_textfile(char *filename);
char **tokenizar(char *buff, char *special);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
int check(char *buffer, stack_t **header, unsigned int line_number);
int check_number(char *num);
int count_ar(char **token);

size_t print_dlistint(stack_t *h);
/*size_t dlistint_len(stack_t *h);*/
stack_t *add_dnodeint(stack_t **head);
/*stack_t *add_dnodeint_end(stack_t **head, unsigned int n);
void free_dlistint(stack_t *head);
stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index);
int sum_dlistint(stack_t *head);
stack_t *insert_dnodeint_at_index(stack_t **h, unsigned int idx, int n);
*/

#endif

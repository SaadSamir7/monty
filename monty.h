#ifndef MONTY_H
#define MONTY_H

#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>


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
 * struct head_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */

typedef struct head_s
{
	char *arg;
	FILE *file;
	char *content;
	int check;
}  head_t;

extern head_t heads;

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
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


int exe(char *content, stack_t **head, unsigned int counter, FILE *file);

/*Handle Func*/
void handle_pop(stack_t **head, unsigned int counter);
void handle_swap(stack_t **head, unsigned int counter);
void handle_add(stack_t **head, unsigned int counter);
void handle_nop(stack_t **head, unsigned int counter);
void handle_sub(stack_t **head, unsigned int counter);
void handle_div(stack_t **head, unsigned int counter);
void handle_mul(stack_t **head, unsigned int counter);
void handle_mod(stack_t **head, unsigned int counter);
void handle_push(stack_t **head, unsigned int number);
void handle_pall(stack_t **head, unsigned int number);
void handle_pint(stack_t **head, unsigned int number);


void handle_pchar(stack_t **head, unsigned int counter);
void handle_pstr(stack_t **head, unsigned int counter);
void handle_rotl(stack_t **head, unsigned int counter);
void handle_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);

/*Add Func*/
void addNode(stack_t **head, int n);
void addQueue(stack_t **head, int n);
void add_queue(stack_t **head, unsigned int counter);
void add_stack(stack_t **head, unsigned int counter);

/*Free Func*/
void free_stack(stack_t *head);
void free_all(stack_t **head);

#endif
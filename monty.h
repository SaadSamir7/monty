#ifndef _MONTY_H_
#define _MONTY_H_

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/* define */
#define notUsed __attribute__((unused))

#define INIT_STATE {NULL, NULL, NULL, NULL, NULL}

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct state_s - opcode and its function
 * @stack: the opcode
 * @file: function to handle the opcode
 * Description: opcode and its function
*/
typedef struct state_s
{
	stack_t *stack;
	FILE *file;
	char *contant;
	char *value;
	char *opCode;
} state_t;

extern state_t head;

typedef void (*op_func)(stack_t **, unsigned int);


int main(int argc, char **argv);
/*opcode functions*/
void handle_push(stack_t **stack, unsigned int line_number);
void handle_pall(stack_t **stack, unsigned int line_number);
void handle_pint(stack_t **stack, unsigned int line_number);
void handle_pop(stack_t **stack, unsigned int line_number);
void handle_swap(stack_t **stack, unsigned int line_number);
void handle_add(stack_t **stack, unsigned int line_number);
void handle_nop(stack_t **stack, unsigned int line_number);
void handle_sub(stack_t **stack, unsigned int line_number);

void free2d(char **tokens);
void free_nodes(void);
void splitString(char *contant, unsigned int cntr, int format);
void findFunc(char *opCode, char *value, unsigned int cntr, int format);
void handleFunc(op_func func, unsigned int cntr, int format);
stack_t *createNode(int n);
void oprationFile(char *filename);
void readFile(FILE *readFile);
int opCode(char *contant, unsigned int cntr, int format);
int not_a_number(char *s);


#endif
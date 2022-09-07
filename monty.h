#ifndef _MONTY_H_
#define _MONTY_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define UNUSED(x) (void)(x)

/**
 * struct var_s - struct to contain the main variables of the Monty interpreter
 * @queue: flag to determine if in stack vs queue mode
 * @stack_len: length of the stack
 */
typedef struct var_s
{
	int queue;
	size_t stack_len;
} var_t;

#define STACK 0
#define QUEUE 1
/* global struct to work with queue an lentgh*/
extern var_t var;

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
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct check_valid_erros_e - structure that check valid errors
 * @opcode: opcode error
 * @f: function to handle the opcode
 *
 * Description: opcode error
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct check_valid_erros_e
{
	char *opcode;
	void (*f)(unsigned int line_number);
} check_valid_erros_z;

/* global struct to hold flag for queue and stack length */
var_t var;



/* prototypes needed*/

/* related to compare and match */
void check_if_op_match(char *op, stack_t **stack, unsigned int line_number);

/* op functions*/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void div_m(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void stack_m(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);

/*functions to close processes on exit*/
void free_File_line(int status, void *arg);
void free_stack_list(int status, void *arg);
void close_File(int status, void *arg);



/* related to add nodes*/
stack_t *add_node(stack_t **stack, const int n);

/*error handlers, print cutomize messages*/
void error_handler(char *op_or_error, unsigned int Linenumber);
void error_handler_add(unsigned int number);
void malloc_fails(unsigned int Linenumber);
void error_isnot_int(unsigned int Linenumber);
void error_empty_stack(unsigned int Linenumber);
void error_pchar(unsigned int Linenumber);
void isnot_assci(unsigned int Linenumber);
void error_sub(unsigned int Linenumber);
void error_pint(unsigned int Linenumber);
void error_mod(unsigned int Linenumber);
void error_div_by_0(unsigned int Linenumber);
void wrong_arguments(unsigned int Linenumber);
void error_fopen(char *argument);
void error_swap(unsigned int Linenumber);
void error_div(unsigned int Linenumber);
void error_mul(unsigned int Linenumber);


#endif /* _MONTY_H_ */

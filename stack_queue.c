#include "monty.h"
/**
 * stack_m - sets the format of the data to a stack (LIFO).
 * @stack: double pointer to head of stack
 * Description: This is the default behavior of the program.
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void stack_m(stack_t **stack, unsigned int Linenumber)
{
	UNUSED(stack);
	UNUSED(Linenumber);
	var.queue = STACK;
}

/**
 * queue -  sets the format of the data to a queue (FIFO).
 * @stack: double pointer to head of stack
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void queue(stack_t **stack, unsigned int Linenumber)
{
	UNUSED(stack);
	UNUSED(Linenumber);
	var.queue = QUEUE;
}

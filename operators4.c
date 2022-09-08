#include "monty.h"

/**
 * mul - multiplies the second top element of the stack with the top element.
 * @stack: double pointer to head of stack
 * @Linenumber: line number of current operation
 *
 *
 *
 * mul - multiplies the second top element of stack with top element
 *
 * Return: void
 */
void mul(stack_t **stack, unsigned int Linenumber)
{
	stack_t *tmp = *stack;
	int sub = 0;

	if (var.stack_len < 2)
	{
		error_handler("error_mul", Linenumber);
	}
	tmp = *stack;
	sub = tmp->next->n * tmp->n;
	tmp->next->n = sub;
	pop(stack, Linenumber);
}

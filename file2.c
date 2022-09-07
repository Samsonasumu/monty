#include "monty.h"
#include <ctype.h>

/**
 * pop - removes the top element of the stack.
 * @stack: double pointer to head of stack
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int Linenumber)
{
	stack_t *tmp = *stack;

	if (var.stack_len == 0)
	{
		error_handler("empty_stack", Linenumber);
	}
	(*stack)->next->prev = (*stack)->prev;
	(*stack)->prev->next = (*stack)->next;
	/* if there are mor than 1 nodes we move the pointer*/
	if (var.stack_len != 1)
		*stack = (*stack)->next;
	/* if not , we just free*/
	else
		*stack = NULL;
	free(tmp);
	var.stack_len--;
}

/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: double pointer to head of stack
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int Linenumber)
{
	stack_t *tmp = *stack;
	/*if stack empty print error*/
	if (var.stack_len == 0)
	{
		error_handler("pchar_error", Linenumber);
	}
	/*making sure we ge only assci format*/
	if (!isascii(tmp->n))
	{
		error_handler("isnot_assci", Linenumber);
	}

	printf("%c\n", tmp->n);
}

/**
 * sub - subtracts the top element from the second top element of the stack.
 * @stack: double pointer to head of stack
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int Linenumber)
{
	stack_t *tmp = *stack;
	int sub = 0;
	/* operation only aviable if there are more than 1 node*/
	if (var.stack_len < 2)
	{
		error_handler("error_sub", Linenumber);
	}
	tmp = *stack;
	sub = tmp->next->n - tmp->n;
	tmp->next->n = sub;
	/* we use pop to delete top node*/
	pop(stack, Linenumber);
}

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: double pointer to head of stack
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int Linenumber)
{

	stack_t *tmp = *stack;
	/*opetarion only aviable if more than 0 nodes*/
	if (var.stack_len == 0)
	{
		error_handler("error_pint", Linenumber);
	}
	printf("%d\n", tmp->n);
}

/**
 * mod - the division of the second top element by the top element.
 * @stack: double pointer to head of stack
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int Linenumber)
{
	stack_t *tmp = *stack;
	int sub = 0;
	/* operation only aviable if there are more than 1 node*/
	if (var.stack_len < 2)
	{
		error_handler("error_mod", Linenumber);
	}
	/* if the second top node is 0 , op not aviable*/
	if (tmp->n == 0)
	{
		error_handler("error_div_by_0", Linenumber);
	}
	tmp = *stack;
	sub = tmp->next->n % tmp->n;
	tmp->next->n = sub;
	/* here we deletee node from the top*/
	pop(stack, Linenumber);
}

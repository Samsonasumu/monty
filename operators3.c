#include "monty.h"
#include <ctype.h>
/**
 * pstr - prints the string starting at the top of the stack.
 * @stack: double pointer to head of stack
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void pstr(stack_t **stack, unsigned int Linenumber)
{
	stack_t *temp;
	int cha;

	UNUSED(Linenumber);

	temp = *stack;
	while (temp != NULL)
	{
		cha = temp->n;
		/* is there is no assci we break*/
		if (!isascii(cha) || cha == 0)
			break;
		putchar(cha);
		temp = temp->next;
		/* break loop condition*/
		/* take in count that stack is a circle list*/
		if (temp == *stack)
			break;
	}
	putchar('\n');
}

/**
 * rotl - The top element becomes the last one,the second top becomes the first
 * @stack: double pointer to head of stack
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void rotl(stack_t **stack, unsigned int Linenumber)
{
	stack_t *tmp = *stack;

	UNUSED(Linenumber);
	/*here we just poin to the next node*/
	if (*stack)
	{
		*stack = tmp->next;
	}
}

/**
 * rotr - The last element of the stack becomes the top element of the stack
 * @stack: double pointer to head of stack
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void rotr(stack_t **stack, unsigned int Linenumber)
{
	stack_t *tmp = *stack;

	UNUSED(Linenumber);
	/* we just have to point the prev node*/
	if (*stack)
	{
		*stack = tmp->prev;
	}
}

/**
 * swap - swaps the top two elements of the stack.
 * @stack: double pointer to head of stack
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int Linenumber)
{
	stack_t *temporal;
	/*operation avaiable only if there are more thant 2 nodes*/
	if (var.stack_len < 2)
	{
		error_handler("error_swap", Linenumber);
	}
	/* if only two nodes we just point next*/
	if (var.stack_len == 2)
	{
		*stack = (*stack)->next;
		return;
	}
	temporal = (*stack)->next;
	temporal->prev = (*stack)->prev;
	(*stack)->prev->next = temporal;
	(*stack)->prev = temporal;
	(*stack)->next = temporal->next;
	temporal->next->prev = *stack;
	temporal->next = *stack;
	*stack = temporal;
}

/**
 * div_m -  divides the second top element of the stack by the top element.
 * @stack: double pointer to head of stack
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void div_m(stack_t **stack, unsigned int Linenumber)
{
	int number;
	/*operation avaiable only if there are more thant 2 nodes*/
	if (var.stack_len < 2)
	{
		error_handler("error_div", Linenumber);
	}
	number = (*stack)->n;
	/* we delete top element*/
	pop(stack, Linenumber);
	/* 0 not allowed*/
	if (number == 0)
	{
		error_handler("error_div_by_0", Linenumber);
	}
	(*stack)->n /= number;
}

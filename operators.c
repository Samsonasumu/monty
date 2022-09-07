#include "monty.h"
#include <ctype.h>

/**
 * pall -  prints all the values on the stack, starting from the top.
 * @stack: double pointer to head of stack
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int Linenumber)
{
	stack_t *head;

	UNUSED(Linenumber);
	head = *stack;
	/* loop to print all numbers from each node*/
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
		/*condition to end a circular loop*/
		if (head == *stack)
		{
			return;
		}
	}

}

/**
 * check_for_digit - check if digit is an integer
 * @arguments: double pointer to head of stack
 *
 * Return: void
 */
static int check_for_digit(char *arguments)
{
	int index;

	for (index = 0; arguments[index]; index++)
	{
		/* here we allow negative numbers an 0*/
		if (arguments[index] == '-' && index == 0)
			continue;
		/* return 1 is is digit*/
		if (isdigit(arguments[index]) == 0)
			return (1);
	}
	/* 0 if not*/
	return (0);
}
/**
 * push - print value on top of `stack', or exit if stack is empty
 * @stack: double pointer to head of stack
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int Linenumber)
{
	char *arguments;
	int number;

	arguments = strtok(NULL, "\n\t ");
	/*make sure there are just int*/
	if (arguments == NULL || check_for_digit(arguments))
	{
		error_handler("is_not_int", Linenumber);
	}
	/* we use atoi to make int variable from char*/
	number = atoi(arguments);
	if (!add_node(stack, number))
	{
		error_handler("malloc_fails", Linenumber);
	}
	/* here we control the numbers of nodes*/
	var.stack_len++;
}

/**
 * nop -  does not do anything.
 * @stack: double pointer to head of stack
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void nop(stack_t **stack, unsigned int Linenumber)
{
	UNUSED(stack);
	UNUSED(Linenumber);
}

/**
 * add - adds the top two elements of the stack
 * @stack: double pointer to head of stack
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int Linenumber)
{
	int number = 0;
	/*if we have less than two nodes, we can't add*/
	if (var.stack_len < 2)
	{
		error_handler("error_add", Linenumber);
	}
	number += (*stack)->n;
	/* we use pop to delete the top node and get the new one*/
	pop(stack, Linenumber);
	/* here we add the new node element */
	(*stack)->n += number;
}

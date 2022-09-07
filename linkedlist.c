#include "monty.h"
/**
 * add_node - add a new node to a circular linked list
 * @stack: pointer to double linked list
 * @n: integer
 * Return: Void
 */

stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *new;

	if (stack == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	if (*stack == NULL)
	{
		new->prev = new;
		new->next = new;
	}
	else
	{
		(*stack)->prev->next = new;
		new->prev = (*stack)->prev;
		(*stack)->prev = new;
		new->next = *stack;
	}
	/*here we deal with STACK and QUEUE*/
	if (var.queue == STACK || var.stack_len == 0)
		*stack = new;
	return (new);
}

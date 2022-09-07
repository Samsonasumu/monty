#include "monty.h"

/**
 * error_handler_add - customize message if add op fails
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void error_handler_add(unsigned int Linenumber)
{
	dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", Linenumber);
	exit(EXIT_FAILURE);
}
/**
 *malloc_fails - customize message if malloc fails
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void malloc_fails(unsigned int Linenumber)
{
	UNUSED(Linenumber);
	dprintf(STDERR_FILENO, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 *error_isnot_int - cutomize message if not int
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void error_isnot_int(unsigned int Linenumber)
{
	dprintf(STDERR_FILENO, "L%u: usage: push integer\n", Linenumber);
	exit(EXIT_FAILURE);
}

/**
 *error_empty_stack - customize message if empty stack
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void error_empty_stack(unsigned int Linenumber)
{
	dprintf(STDERR_FILENO,
			"L%u: can't pop an empty stack\n",
			Linenumber);
		exit(EXIT_FAILURE);
}
/**
 * error_pchar - cutomize message if pchar op fails
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void error_pchar(unsigned int Linenumber)
{
	dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n", Linenumber);
	exit(EXIT_FAILURE);
}

#include "monty.h"

/**
 * wrong_arguments - customize message if wrong arguments
 * @Linenumber: line number of current operation
 *
 * Return: void
 *
 *
 */
void wrong_arguments(unsigned int Linenumber)
{
	UNUSED(Linenumber);
	dprintf(STDERR_FILENO, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * error_fopen - customize message if fopen fails
 * @argument: file that could not be open
 *
 * Return: void
 */
void error_fopen(char *argument)
{
	dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argument);
	exit(EXIT_FAILURE);
}

/**
 * error_swap - customize message if is swap op fails
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void error_swap(unsigned int Linenumber)
{
		dprintf(STDERR_FILENO,
			"L%u: can't swap, stack too short\n",
			Linenumber);
		exit(EXIT_FAILURE);
}

/**
 * error_div - customize message if div op fails
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void error_div(unsigned int Linenumber)
{
		dprintf(STDERR_FILENO,
			"L%u: can't div, stack too short\n",
			Linenumber);
		exit(EXIT_FAILURE);
}

/**
 *  error_mul - customize message if mul op fails
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void error_mul(unsigned int Linenumber)
{
	dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n", Linenumber);
	exit(EXIT_FAILURE);
}

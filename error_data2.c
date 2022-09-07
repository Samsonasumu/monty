#include "monty.h"

/**
 * isnot_assci - customize message if is not assci
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void isnot_assci(unsigned int Linenumber)
{
		dprintf(STDERR_FILENO,
				"L%u: can't pchar, value out of range\n",
				Linenumber);
		exit(EXIT_FAILURE);
}

/**
 * error_sub - customize message if sub op fails
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void error_sub(unsigned int Linenumber)
{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n", Linenumber);
		exit(EXIT_FAILURE);
}

/**
 * error_pint - customize message if pint op fails
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void error_pint(unsigned int Linenumber)
{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", Linenumber);
		exit(EXIT_FAILURE);
}

/**
 * error_mod - customize message if mod fails
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void error_mod(unsigned int Linenumber)
{
	dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n", Linenumber);
	exit(EXIT_FAILURE);
}

/**
 * error_div_by_0 - customize message if div by 0
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void error_div_by_0(unsigned int Linenumber)
{
	dprintf(STDERR_FILENO, "L%u: division by zero\n", Linenumber);
	exit(EXIT_FAILURE);
}

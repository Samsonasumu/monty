#include "monty.h"

/**
 * free_File_line - free line pointer returned by getline
 * @status: exit status
 * @argument: pointer to line
 *
 * Return: void
 */
void free_File_line(int status, void *argument)
{
	/* get argument*/
	char **lineptr = argument;

	UNUSED(status);
	if (*lineptr != NULL)
		free(*lineptr);
}

/**
 * free_stack_list - free stack on exit
 * @status: exit status
 * @argument: pointer to line
 *
 * Return: void
 */
void free_stack_list(int status, void *argument)
{
	stack_t **stack;
	stack_t *next;

	UNUSED(status);

	stack = (stack_t **)argument;
	/*break circle*/
	if (*stack)
	{
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
	/* now we can feree al nodes*/
	while (*stack != NULL)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
	/*make sure to set stack len in 0*/
	var.stack_len = 0;
}

/**
 * close_File - clse "file" on exit
 * @status: exit status
 * @argument: pointer to line
 *
 * Return: void
 */
void close_File(int status, void *argument)
{
	FILE *File;

	UNUSED(status);
	/* close file: it's a must procedure*/
	File = (FILE *) argument;
	fclose(File);
}

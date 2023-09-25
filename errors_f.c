#include "monty.h"

/**
 * err - Prints appropiate error messages determined by their error code.
 * @error_code: The error codes are the following:
 * (1) => User does not give any file or more than one file to the program.
 * (2) => File provided is not a file that can be opened or read.
 * (3) => File provided contains an invalid instruction.
 * (4) => Program is unable to malloc more memory.
 * (5) => Parameter passed to the instruction "push" is not an int.
 * (6) => Stack it empty for pint.
 * (7) => Stack it empty for pop.
 * (8) => Stack is too short for operation.
 */
void err(int error_code, ...)
{
	va_list arg;
	char *op;
	int line_n;

	va_start(arg, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
					va_arg(arg, char *));
			break;
		case 3:
			line_n = va_arg(arg, int);
			op = va_arg(arg, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_n, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(arg, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_err - handles errors.
 * @error_code: The error codes are the following:
 * (6) => stack it empty for pint.
 * (7) => stack it empty for pop.
 * (8) => stack too short for operation.
 * (9) => Division by 0.
 */
void more_err(int error_code, ...)
{
	va_list arg;
	char *op;
	int line_n;

	va_start(arg, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
					va_arg(arg, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
					va_arg(arg, int));
			break;
		case 8:
			line_n = va_arg(arg, unsigned int);
			op = va_arg(arg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_n, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
					va_arg(arg, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - handles errors.
 * @error_code: The error codes are the following:
 * (10) ~> number inside a node is outside ASCII bounds.
 * (11) ~> empty stack.
 */
void string_err(int error_code, ...)
{
	va_list arg;
	int line_n;

	va_start(arg, error_code);
	line_n = va_arg(arg, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_n);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_n);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

#include "main.h"

/**
 * get_size - a functions that computes the size to cast the argument
 * @format: pointer to constant char string specifying the format of the input
 * @n: pointer to an integer that stores the size of the input data
 * Return: precise size
 */

int get_size(const char *format, int *n)
{
	int curr_n = *n + 1;
	int size = 0;

	if (format[curr_n] == 'l')
		size = S_LONG;
	else if (format[curr_n] == 'h')
		size = S_SHORT;

	if (size == 0)
		*n = curr_n - 1;
	else
		*n = curr_n;

	return (size);
}


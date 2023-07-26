#include "main.h"

/**
 * my_printf - a function that printing formatted output to the standard output
 * @format: pointer to a string specifying the format of the data to be printed
 * @... : variable number of arguments after the format string
 * Return: Printed chars.
 */
int my_printf(const char *format, ...)
void print_buffer(char buffer[], int *buff_indx);
{
	int n, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_indx = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (n = 0; format && format[n] != '\0'; n++)
	{
		if (format[n] != '%')
		{
			buffer[buff_indx++] = format[n];
			if (buff_indx == BUFF_SIZE)
			print_buffer(buffer, &buff_indx);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_indx);
			flags = get_flags(format, &n);
			width = get_width(format, &n, list);
			precision = get_precision(format, &n, list);
			size = get_size(format, &n);
			n++;
			printed = handle_print(format, &n, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_indx);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: array of characters that contains the characters to be printed.
 * @buff_indx:  pointer to an int that pointing to index position of the buffer
 */

void print_buffer(char buffer[], int *buff_indx)
{
	if (*buff_indx > 0)
		write(1, &buffer[0], *buff_indx);

	*buff_indx = 0;
}


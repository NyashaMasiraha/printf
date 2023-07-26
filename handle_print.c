#include "main.h"

/**
 * handle_print - print formatted output to the buffer and update buffer index
 * @fmt: pointer to constant char string specifying format string to be printed
 * @ind: pointer to the index position of the buffer.
 * @list: variable argumet list containing arguments to be printed
 * @buffer: an array of chars that is used to store the chars that are printed.
 * @flags: an integer value that specifies the modifiers for the format string.
 * @width: integer value specifying minimum field width for the format string.
 * @precisio: integer value that specifies the precision for the format string.
 * @size:  integer value that specifies the size of the buffer
 * Return: 1 or 2;
 */

int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int n, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (n = 0; fmt_types[n].fmt != '\0'; n++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[n].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}


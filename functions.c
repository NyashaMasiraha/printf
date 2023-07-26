#include "main.h"

/**
 * print_char - Prints a characer
 * @args: variable argument list
 * @size: lenght of character to be manipulated
 * @width: minimum number of characters to be printed or character width
 * @precision: number of char to be printed
 * @buffer: array to print, buffer to store the data or output being processed
 * @flags: number of flags that modify the behaviour of the function
 * Return: total number of printed chars.
 */
int print_char(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/**
 * print_percent - Prints a percent sign
 * @types: argument types
 * @size: lenght of character to be printed
 * @width: minimum number of characters to be printed
 * @precision: precise number of chars to be printed
 * @buffer: array to print, buffer to store the data or output being processed
 * @flags: number of flags that modify the behaviour of the data
 * return: % character
 */
int print_percent(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * print_string - Prints a string
 * @types: variable argument types
 * @size: length of string to be printed
 * @width: minimum number of characters of the string to be printed
 * @precision: number of characters to be printed
 * @buffer: array to print, buffer to store the data being processed
 * @flags: number of flags that modify the behaviour of the fucntion
 * Return: total number of printed chars.
 */
int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = 0, n;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (n = width - length; n > 0; n--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (n = width - length; n > 0; n--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}

/*
 * print_int - Print integer values
 * @args: variable argument list
 * @size: integer length
 * @width: minimum number of digit of the integer to print
 * @precision: number of digits to be printed after after a decimal point
 * @buffer: array to print, buffer to store the data being processed
 * @flags: number of flgas that modify the behaviour of the function
 * Return: integer
 */

int print_int(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	int is_negative = 0;
	long int m = va_arg(types, long int);
	unsigned long int num;

	m = convert_size_number(m, size);

	if (m == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)m;

	if (m < 0)
	{
		num = (unsigned long int)((-1) * m);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[j--] = (num % 10) + '0';
		num /= 10;
	}

	j++;

	return (write_number(is_negative, buffer, flags, size,
				width, precision, j));
}

/**
 * print_binary - Prints an unsigned number
 * @types: variable argument types
 * @size: number length
 * @width: minimum number of characters to be printed
 * @precision: numbers of characters to be printed
 * @buffer: array to print, buffer to store data being processed
 * @flags: number of flags that affect the behavour of the function
 * Return: binary
 */

int print_binary(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	unsigned int x, y, h, sum;
	unsigned int i[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	x = va_arg(types, unsigned int);
	y = 2147483648;
	i[0] = x / y;
	for (h = 1; h < 32; h++)
	{
		y /= 2;
		i[j] = (x / y) % 2;
	}
	for (h = 0, sum = 0, count = 0; h < 32; h++)
	{
		sum += i[j];
		if (sum || j == 31)
		{
			char z = '0' + a[j];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}


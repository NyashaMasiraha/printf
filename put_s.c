#include "main.h"

/*
 * put_s: function that prints a string
 * @indx: the buffer index
 * @string: pointet to the string to be printed
 * description: a function that prints and returns the strings from the buffer
 * return: r_value
 */

int put_s(char *string)
{
	int indx = 0, r_value = 0;

	if (string)
	{
		while (string[indx] != '\0')
		{
			putchr(string[indx]);
			r_value += 1;
			indx++;
		}
	}
	return (r_value);
}

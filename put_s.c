#include "main.h"

int put_s(char *string)
{
	int indx = 0, r_value = 0;

	if(string)
	{
		while (string[i] != '\0')
		{
			putchr(string[i]);
			r_value += 1;
			i++;
		}
	}
	return(r_value);
}

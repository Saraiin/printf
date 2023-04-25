#include "main.h"

/**
 * gwidth - calculates width for printing
 * @format: formatted string in which to print the arguments
 * @ag: list of arguments to be printed
 * @list: list of arguments
 *
 * Return: width
 */
int gwidth(const char *format, int *ag, va_list list)
{
	int k;
	int width = 0;

	for (k = *ag + 1; format[k] != '\0'; k++)
	{
		if (ckdigit(format[k]))
		{
			width *= 10;
			width += format[k] - '0';
		}
		else if (format[k] == '*')
		{
			k++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*ag = k - 1;

	return (width);
}

#include "main.h"
/**
 * gprecision - precision for printing
 * @format: formatted string
 * @i: list of arguments to be printed
 * @list: list of arguments
 * Return: precision
 */
int gprecision(const char *format, int *i, va_list list)
{
	int precision = -1;
	int k;

	k = *i + 1;
	if (format[k] != ".")
		return (precision);
	precision = 0;
	for (k += 1; format[k] != '\0'; k++)
	{
		if (is_digit(format[k]))
		{
			precision *= 10;
			precision += format[k] - '0';
		}
		else if (format[k] == '*')
		{
			k++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = k - 1;
	return (precision);
}

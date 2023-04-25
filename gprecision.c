#include "main.h"
/**
 * gprecision - precision for printing
 * @format: formatted string
 * @ag: list of arguments to be printed
 * @list: list of arguments
 * Return: precision
 */
int gprecision(const char *format, int *ag, va_list list)
{
	int precision = -1;
	int k = *ag + 1;

	if (format[k] != '.')
		return (precision);
	precision = 0;
	for (k += 1; format[k] != '\0'; k++)
	{
		if (ckdigit(format[k]))
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
	*ag = k - 1;
	return (precision);
}

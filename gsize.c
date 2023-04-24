#include "main.h"
/**
 * gsize - size to cast
 * @format: formatted sting
 * @ag: list of arguments to be printed
 * Return: size
 */
int gsize(const char *format, int *ag)
{
	int k = *ag + 1;
	int size = 0;

	if (format[k] == '1')
		size = S_LONG;
	else if (format(k) == 'h')
		size = S_SHORT;
	if (size == 0)
		*ag = k - 1;
	else
		*ag = k;
	return (size);
}

#include "main.h"

/*** print char ***/

/**
 * pr_char - Prints a character
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int pr_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (character_writer(c, buffer, flags, width, precision, size));
}
/*** PRINT STRING ***/
/**
 * pr_string - prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int pr_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int ln = 0, i; /*ln = length*/
	char *s = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (s == NULL)
	{
		s = "(null)";
		if (precision >= 6)
			s = "      ";
	}
	while (s[ln] != '\0')
		ln++;
	if (precision >= 0 && precision < ln)
		ln = precision;
	if (width > ln)
	{
		if (flags & F_MINUS)
		{
			write(1, &s[0], ln);
			for (i = width - ln; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], ln);
			return (width);
		}
		else
		{
			for (i = width - ln; i > 0; i--)
				write(1, " ", 1);
			write(1, &s[0], ln);
			return (width);
		}
	}
	return (write(1, s, ln));
}
/* print integer */
/**
 * pr_int - print integer
 * @types: Liste of arguments
 * @buffer: Buffer array
 * @flags:  Calculates active flags
 * @width: width.
 * @precision: Precision specification
 * @size: Size
 * Return: Number of character printed
 */
int pr_int(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	unsigned long int nb;
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);

	n = convert_nsize(n, size);
	if (n == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	nb = (unsigned long int)n;

	if (n < 0)
	{
		nb = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (nb > 0)
	{
		buffer[i--] = (nb % 10) + '0';
		nb /= 10;
	}

	i++;
	return (print_string(is_negative, i, buffer, flags, width, precision, size));
}
/** binary **/
/**
 * pr_binary - Prints an unsigned number
 * @types: Liste of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int pr_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int ar[32];
	int ctr;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	ar[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		ar[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, ctr = 0; i < 32; i++)
	{
		sum += ar[i];
		if (sum || i == 31)
		{
			char z = '0' + ar[i];

			write(1, &z, 1);
			ctr++;
		}
	}
	return (ctr);
}


#include "main.h"
/**
 * ckprintable - checks if a character is printable
 * @c: character to be checked
 * Return: 1 on success and 0 on fail
 */
int ckprintable(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}
/**
 * aphexa_code - Append ascci in hexadecimal code to buffer
 * @ascicode: ASSCI CODE
 * @buffer: Array of chars.
 * @i: Index at which to start appending
 * Return: Always 3
 */
int aphexa_code(char ascicode, char buffer[], int i)
{
	char xa[] = "0123456789ABCDEF";

	if (ascicode < 0)
		ascicode *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = xa[ascicode / 16];
	buffer[i] = xa[ascicode % 16];

	return (3);
}
/**
 * ckdigit - checks if a character is a digit
 * @c: Character to be checked
 * Return: 1 if c is a digit, 0 otherwise
 */
int ckdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}
/**
 * convert_nsize - Casts a number to the specified size
 * @n: Number to be casted.
 * @size: Number indicating the type to be casted.
 * Return: Casted value of n
 */
long int convert_nsize(long int n, int size)
{
	if (size == S_LONG)
		return (n);
	else if (size == S_SHORT)
		return ((short)n);
	return ((int)n);
}
/**
 * convert_unsize - Casts a number to the specified size
 * @n: Number to be casted
 * @size: Number indicating the type to be casted
 * Return: Casted value of n
 */
long int convert_unsize(unsigned long int n, int size)
{
	if (size == S_LONG)
		return (n);
	else if (size == S_SHORT)
		return ((unsigned short)n);

	return ((unsigned int)n);
}

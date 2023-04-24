#include "main.h"

/**
 * _printf - function printf
 * @format: format
 * Return: printed characters
 */
int _printf(const char *format, ...)
{
	int charprinted = 0;
	int j, printed = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(list, format);

	for (j = 0; format && format[j] != '\0'; i++)
	{
		if (format[j] != '%')
		{
			buffer[buff_id++] = format[j];
			if (buff_id == BUFF_SIZE)
				print_buffer(buffer, &buff_id);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_id);
			flags = gflags(format, &j);
			width = gwidth(format, &j, list);
			precision = gprecision(format, &j, list);
			size = gsize(format, &j);
			++j;
			printed = argprint(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			charprinted += printed;
		}
	}

	print_buffer(buffer, &buff_id);

	va_end(list);

	return (charprinted);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_id: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_id)
{
	if (*buff_id > 0)
		write(1, &buffer[0], *buff_id);

	*buff_id = 0;
}


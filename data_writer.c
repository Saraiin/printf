#include "main.h"

/************************* CHARACTER WRITER *************************/
/**
 * character_writer - Prints a string
 * @c: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags.
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int character_writer(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0;
	char pd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		pd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = pd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/************************* PRINT STRING *************************/
/**
 * print_string - Prints a string
 * @is_negative: Lista of arguments
 * @id: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int print_string(int is_negative, int id, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - id - 1;
	char pd = ' ', fg = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pd = '0';
	if (is_negative)
		fg = '-';
	else if (flags & F_PLUS)
		fg = '+';
	else if (flags & F_SPACE)
		fg = ' ';

	return (num_write_buf(id, buffer, flags, width, precision,
		length, pd, fg));
}

/**
 * num_write_buf - Write a number using a bufffer
 * @id: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @prec: Precision specifier
 * @length: Number length
 * @pd: Pading char
 * @ec: Extra char
 *
 * Return: Number of printed chars.
 */
int num_write_buf(int id, char buffer[],
	int flags, int width, int prec,
	int length, char pd, char ec)
{
	int i, pd_start = 1;

	if (prec == 0 && id == BUFF_SIZE - 2 && buffer[id] == '0' && width == 0)
		return (0);
	if (prec == 0 && id == BUFF_SIZE - 2 && buffer[id] == '0')
		buffer[id] = pd = ' ';
	if (prec > 0 && prec < length)
		pd = ' ';
	while (prec > length)
		buffer[--id] = '0', length++;
	if (ec != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = pd;
		buffer[i] = '\0';
		if (flags & F_MINUS && pd == ' ')
		{
			if (ec)
				buffer[--id] = ec;
			return (write(1, &buffer[id], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && pd == ' ')
		{
			if (ec)
				buffer[--id] = ec;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[id], length));
		}
		else if (!(flags & F_MINUS) && pd == '0')
		{
			if (ec)
				buffer[--pd_start] = ec;
			return (write(1, &buffer[pd_start], i - pd_start) +
				write(1, &buffer[id], length - (1 - pd_start)));
		}
	}
	if (ec)
		buffer[--id] = ec;
	return (write(1, &buffer[id], length));
}

/**
 * write_un - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @id: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars.
 */
int write_un(int is_negative, int id,
	char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - id - 1, i = 0;
	char pd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && id == BUFF_SIZE - 2 && buffer[id] == '0')
		return (0);

	if (precision > 0 && precision < length)
		pd = ' ';

	while (precision > length)
	{
		buffer[--id] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pd = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = pd;

		buffer[i] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[id], length) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[id], length));
		}
	}

	return (write(1, &buffer[id], length));
}

/**
 * write_mem_addr - Write a memory address
 * @buffer: Arrays of chars
 * @id: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: Wwidth specifier
 * @flags: Flags specifier
 * @pd: Char representing the padding
 * @ec: Char representing extra char
 * @pd_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int write_mem_addr(char buffer[], int id, int length,
	int width, int flags, char pd, char ec, int pd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = pd;
		buffer[i] = '\0';
		if (flags & F_MINUS && pd == ' ')
		{
			buffer[--id] = 'x';
			buffer[--id] = '0';
			if (ec)
				buffer[--id] = ec;
			return (write(1, &buffer[id], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && pd == ' ')
		{
			buffer[--id] = 'x';
			buffer[--id] = '0';
			if (ec)
				buffer[--id] = ec;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[id], length));
		}
		else if (!(flags & F_MINUS) && pd == '0')
		{
			if (ec)
				buffer[--pd_start] = ec;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[pd_start], i - pd_start) +
				write(1, &buffer[id], length - (1 - pd_start) - 2));
		}
	}
	buffer[--id] = 'x';
	buffer[--id] = '0';
	if (ec)
		buffer[--id] = ec;
	return (write(1, &buffer[id], BUFF_SIZE - id - 1));
}

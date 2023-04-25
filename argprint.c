#include "main.h"
/**
 * argprint - prints an argument based on its type
 * @ft: formatted string
 * @list: list of argument
 * @id: index
 * @buffer: array
 * @flags: flags
 * @width: width
 * @precision: Precision
 * @size: size
 * Return: 1
 */
int argprint(const char *ft, int *id, va_list list, char buffer[],
int flags, int width, int precision, int size)
{
	int ln = 0;
	int cprinted = -1;
	int i;
	ft_t ft_types[] = {
		{'c', pr_char}, {'s', pr_string}, {'%', pr_percent},
		{'i', pr_int}, {'d', pr_int}, {'b', pr_binary},
		{'u', pr_unsigned}, {'o', pr_octal}, {'x', pr_hexadecimal},
		{'X', pr_hexa_upper}, {'p', pr_pointer}, {'S', pr_non_printable},
		{'r', pr_reverse}, {'R', pr_rot13string}, {'\0', NULL}
	};
	for (i = 0; ft_types[i].ft != '\0'; i++)
		if (ft[*id] == ft_types[i].ft)
			return (ft_types[i].f(list, buffer, flags, width, precision, size));
	if (ft_types[i].ft == '\0')
	{
		if (ft[*id] == '\0')
			return (-1);
		ln += write(1, "%%", 1);
		if (ft[*id - 1] == ' ')
			ln += write(1, " ", 1);
		else if (width)
		{
			--(*id);
			while (ft[*id] != ' ' && ft[*id] != '%')
				--(*id);
			if (ft[*id] == ' ')
				--(*id);
			return (1);
		}
		ln += write(1, &ft[*id], 1);
		return (ln);
	}
	return (cprinted);
}


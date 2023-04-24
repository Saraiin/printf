#include "main.h"

/**
 * gflags - calculates all active flags
 * @format: formatted  the string in which to print the arguments
 * @ag: take a parameter
 * Return: flags
 */
int gflags(const char *format, int *ag)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, k;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, f_HASH, F_SPACE, 0};

	for (k = *ag + 1; format[k] != '\0'; k++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[k] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*ag = k - 1;

	return (flags);
}

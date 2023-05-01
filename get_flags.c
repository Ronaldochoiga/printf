#include "main.h"

/**
 * get_f - Calc f
 * @format: Format where to print arg
 * @i: tak par
 * Return: flg
 */
int get_f(const char *format, int *i)
{
	int j, ci;
	int f = 0;
	const char F_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int F_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (ci = *i + 1; format[ci] != '\0'; ci++)
	{
		for (j = 0; F_CH[j] != '\0'; j++)
			if (format[ci] == F_CH[j])
			{
				f |= F_ARR[j];
				break;
			}

		if (F_CH[j] == 0)
			break;
	}

	*i = ci - 1;

	return (f);
}

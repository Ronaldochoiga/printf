#include "main.h"

/**
 * get_s - Calc size
 * @format: Format
 * @i: List of arg
 * Return: size
 */
int get_s(const char *format, int *i)
{
	int ci = *i + 1;
	int s = 0;

	if (format[ci] == 'l')
		s = S_LONG;
	else if (format[ci] == 'h')
		s = S_SHORT;

	if (s == 0)
		*i = ci - 1;
	else
		*i = ci;

	return (s);
}

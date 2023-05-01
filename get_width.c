#include "main.h"

/**
 * get_w - Calc w
 * @format: Format
 * @i: List of arg
 * @list: list of arg
 *
 * Return: w.
 */
int get_w(const char *format, int *i, va_list list)
{
	int ci;
	int w = 0;

	for (ci = *i + 1; format[ci] != '\0'; ci++)
	{
		if (is_digit(format[ci]))
		{
			w *= 10;
			w += format[ci] - '0';
		}
		else if (format[ci] == '*')
		{
			ci++;
			w = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = ci - 1;

	return (w);
}

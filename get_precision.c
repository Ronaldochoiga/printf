#include "main.h"

/**
 * get_pr - Calc the pr
 * @format: Format
 * @i: List of arg
 * @list: list of argu
 * Return: Pr.
 */
int get_pr(const char *format, int *i, va_list list)
{
	int ci = *i + 1;
	int pr = -1;

	if (format[ci] != '.')
		return (pr);

	pr = 0;

	for (ci += 1; format[ci] != '\0'; ci++)
	{
		if (is_digit(format[ci]))
		{
			pr *= 10;
			pr += format[ci] - '0';
		}
		else if (format[ci] == '*')
		{
			ci++;
			pr = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = ci - 1;

	return (pr);
}

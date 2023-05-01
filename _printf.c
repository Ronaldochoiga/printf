#include "main.h"
#include <stdarg.h>
void print_bu(char bu[], int *buff_ind);

/**
 * _printf - main function
 * @format: how it should be
 * Return: pc
 */
int _printf(const char *format, ...)
{
	int i, p = 0, p_chars = 0;
	int f, w, pr, s, buff_ind = 0;
	va_list list;
	char bu[BUFF_S];
	va_start(list, format);
	if (format == NULL)
		return (-1);



	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			bu[buff_ind++] = format[i];
			if (buff_ind == BUFF_S)
				print_bu(bu, &buff_ind);

			p_chars++;
		}
		else
		{
			print_bu(bu, &buff_ind);
			f = get_f(format, &i);
			w = get_w(format, &i, list);
			pr = get_pr(format, &i, list);
			s = get_s(format, &i);
			++i;
			p = handle_print(format, &i, list, bu,
				f, w, pr, s);
			if (p == -1)
				return (-1);
			p_chars += p;
		}
	}

	print_bu(bu, &buff_ind);

	va_end(list);

	return (p_chars);
}

/**
 * print_bu - main function
 * @bu: fp
 * @buff_ind: fp
 */
void print_bu(char bu[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &bu[0], *buff_ind);

	*buff_ind = 0;
}

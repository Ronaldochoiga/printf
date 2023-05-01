#include "main.h"

/**
 * handle_print - Prints an arg
 * @fmt: Format
 * @list: List of arg
 * @ind: ind.
 * @bu: Bu arr
 * @f: Calc
 * @w: get w.
 * @pr: Pr spec
 * @s: S specify
 * Return: 1
 */
int handle_print(const char *fmt, int *ind, va_list list, char bu[],
	int f, int w, int pr, int s)
{
	int i, unkl = 0, p_chars = -1;
	fmt_t ft[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; ft[i].fmt != '\0'; i++)
		if (fmt[*ind] == ft[i].fmt)
			return (ft[i].fn(list, bu, f, w, pr, s));

	if (ft[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unkl += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unkl += write(1, " ", 1);
		else if (w)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unkl += write(1, &fmt[*ind], 1);
		return (unkl);
	}
	return (p_chars);
}

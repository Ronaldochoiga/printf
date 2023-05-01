#include "main.h"

/**
 * print_pointer - Prints tvalue of pointer
 * @types: List of arg
 * @bu: Bu arr
 * @f:  Calc f
 * @w: get w
 * @pr: Pr spec
 * @s: S specif
 * Return: Num of char
 */
int print_pointer(va_list types, char bu[],
	int f, int w, int pr, int s)
{
	char ec = 0, padd = ' ';
	int ind = BUFF_S - 2, len = 2, padd_start = 1;
	unsigned long num_a;
	char map_to[] = "0123456789abcdef";
	void *a = va_arg(types, void *);

	UNUSED(w);
	UNUSED(s);

	if (a == NULL)
		return (write(1, "(nil)", 5));

	bu[BUFF_S - 1] = '\0';
	UNUSED(pr);

	num_a = (unsigned long)a;

	while (num_a > 0)
	{
		bu[ind--] = map_to[num_a % 16];
		num_a /= 16;
		len++;
	}

	if ((f & F_ZERO) && !(f & F_MINUS))
		padd = '0';
	if (f & F_PLUS)
		ec = '+', len++;
	else if (f & F_SPACE)
		ec = ' ', len++;

	ind++;

	return (write_pointer(bu, ind, len,
		w, f, padd, ec, padd_start));
}

/**
 * print_non_printable - Prints ascii codes
 * @types: List of arg
 * @bu: Bu arr
 * @f:  Calc
 * @w: get w
 * @pr: Pr spec
 * @s: S specify
 * Return: Num of chars printed
 */
int print_non_printable(va_list types, char bu[],
	int f, int w, int pr, int s)
{
	int i = 0, offset = 0;
	char *sr = va_arg(types, char *);

	UNUSED(f);
	UNUSED(w);
	UNUSED(pr);
	UNUSED(s);

	if (sr == NULL)
		return (write(1, "(null)", 6));

	while (sr[i] != '\0')
	{
		if (is_printable(sr[i]))
			bu[i + offset] = sr[i];
		else
			offset += append_hexa_code(sr[i], bu, i + offset);

		i++;
	}

	bu[i + offset] = '\0';

	return (write(1, bu, i + offset));
}

/**
 * print_reverse - Prints in reverse
 * @types: List of arg
 * @bu: Bu arr to handle print
 * @f:  Calculate f
 * @w: get w
 * @pr: Pr spef
 * @s: S specify
 * Return: Num of chars printed
 */

int print_reverse(va_list types, char bu[],
	int f, int w, int pr, int s)
{
	char *sr;
	int i, co = 0;

	UNUSED(bu);
	UNUSED(f);
	UNUSED(w);
	UNUSED(s);

	sr = va_arg(types, char *);

	if (sr == NULL)
	{
		UNUSED(pr);

		sr = ")Null(";
	}
	for (i = 0; sr[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = sr[i];

		write(1, &z, 1);
		co++;
	}
	return (co);
}
/**
 * print_rot13string - Print rot13
 * @types: Lista of arguments
 * @bu: Bu array to handle print
 * @f:  Calculate f
 * @w: get w
 * @pr: Pr spec
 * @s: S specify
 * Return: Num of cha
 */
int print_rot13string(va_list types, char bu[],
	int f, int w, int pr, int s)
{
	char x;
	char *sr;
	unsigned int i, j;
	int co = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char t[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	sr = va_arg(types, char *);
	UNUSED(bu);
	UNUSED(f);
	UNUSED(w);
	UNUSED(pr);
	UNUSED(s);

	if (sr == NULL)
		sr = "(AHYY)";
	for (i = 0; sr[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == sr[i])
			{
				x = t[j];
				write(1, &x, 1);
				co++;
				break;
			}
		}
		if (!in[j])
		{
			x = sr[i];
			write(1, &x, 1);
			co++;
		}
	}
	return (co);
}

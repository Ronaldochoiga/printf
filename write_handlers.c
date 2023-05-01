#include "main.h"

/**
 * handle_write_char - print string
 * @c: characters
 * @bu: Bu arr
 * @f:  Calc
 * @w: get w.
 * @pr: pr spec
 * @s: S spec
 * Return: Num of printed characters
 */
int handle_write_char(char c, char bu[],
	int f, int w, int pr, int s)
{
	int i = 0;
	char padd = ' ';

	UNUSED(pr);
	UNUSED(s);

	if (f & F_ZERO)
		padd = '0';

	bu[i++] = c;
	bu[i] = '\0';

	if (w > 1)
	{
		bu[BUFF_S - 1] = '\0';
		for (i = 0; i < w - 1; i++)
			bu[BUFF_S - i - 2] = padd;

		if (f & F_MINUS)
			return (write(1, &bu[0], 1) +
					write(1, &bu[BUFF_S - i - 1], w - 1));
		else
			return (write(1, &bu[BUFF_S - i - 1], w - 1) +
					write(1, &bu[0], 1));
	}

	return (write(1, &bu[0], 1));
}

/**
 * write_number - Prints a string
 * @is_negative: List of arg
 * @ind: chaacter
 * @bu: Bu arr
 * @f:  Calc f
 * @w: get w.
 * @pr: pr specif
 * @s: S specif
 * Return: Num of print chars
 */
int write_number(int is_negative, int ind, char bu[],
	int f, int w, int pr, int s)
{
	int length = BUFF_S - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(s);

	if ((f & F_ZERO) && !(f & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (f & F_PLUS)
		extra_ch = '+';
	else if (f & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, bu, f, w, pr,
		length, padd, extra_ch));
}

/**
 * write_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the bu
 * @bu: Bu
 * @f: F
 * @w: w
 * @prec: Pr spec
 * @length: Num len
 * @padd: Padding character
 * @extra_c: Ex character
 * Return: Num of p chars
 */
int write_num(int ind, char bu[],
	int f, int w, int prec,
	int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == BUFF_S - 2 && bu[ind] == '0' && w == 0)
		return (0);
	if (prec == 0 && ind == BUFF_S - 2 && bu[ind] == '0')
		bu[ind] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		bu[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (w > length)
	{
		for (i = 1; i < w - length + 1; i++)
			bu[i] = padd;
		bu[i] = '\0';
		if (f & F_MINUS && padd == ' ')
		{
			if (extra_c)
				bu[--ind] = extra_c;
			return (write(1, &bu[ind], length) + write(1, &bu[1], i - 1));
		}
		else if (!(f & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				bu[--ind] = extra_c;
			return (write(1, &bu[1], i - 1) + write(1, &bu[ind], length));
		}
		else if (!(f & F_MINUS) && padd == '0')
		{
			if (extra_c)
				bu[--padd_start] = extra_c;
			return (write(1, &bu[padd_start], i - padd_start) +
				write(1, &bu[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		bu[--ind] = extra_c;
	return (write(1, &bu[ind], length));
}

/**
 * write_unsgnd - returns unsd num
 * @is_negative: Num showing neg
 * @ind: start of bu
 * @bu: Arr
 * @f: F spec
 * @w: W spec
 * @pr: Pr spec
 * @s: S spec
 *
 * Return: Num of chars
 */
int write_unsgnd(int is_negative, int ind,
	char bu[],
	int f, int w, int pr, int s)
{

	int length = BUFF_S - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(s);

	if (pr == 0 && ind == BUFF_S - 2 && bu[ind] == '0')
		return (0);

	if (pr > 0 && pr < length)
		padd = ' ';

	while (pr > length)
	{
		bu[--ind] = '0';
		length++;
	}

	if ((f & F_ZERO) && !(f & F_MINUS))
		padd = '0';

	if (w > length)
	{
		for (i = 0; i < w - length; i++)
			bu[i] = padd;

		bu[i] = '\0';

		if (f & F_MINUS)
		{
			return (write(1, &bu[ind], length) + write(1, &bu[0], i));
		}
		else
		{
			return (write(1, &bu[0], i) + write(1, &bu[ind], length));
		}
	}

	return (write(1, &bu[ind], length));
}

/**
 * write_pointer - gives an aadr
 * @bu: Arr of char
 * @ind: Index for printing
 * @length: Len
 * @w: W spec
 * @f: F spec
 * @padd: padd
 * @extra_c: fp
 * @padd_start: the start of the padd
 * Return: write characters
 */
int write_pointer(char bu[], int ind, int length,
	int w, int f, char padd, char extra_c, int padd_start)
{
	int i;

	if (w > length)
	{
		for (i = 3; i < w - length + 3; i++)
			bu[i] = padd;
		bu[i] = '\0';
		if (f & F_MINUS && padd == ' ')
		{
			bu[--ind] = 'x';
			bu[--ind] = '0';
			if (extra_c)
				bu[--ind] = extra_c;
			return (write(1, &bu[ind], length) + write(1, &bu[3], i - 3));
		}
		else if (!(f & F_MINUS) && padd == ' ')
		{
			bu[--ind] = 'x';
			bu[--ind] = '0';
			if (extra_c)
				bu[--ind] = extra_c;
			return (write(1, &bu[3], i - 3) + write(1, &bu[ind], length));
		}
		else if (!(f & F_MINUS) && padd == '0')
		{
			if (extra_c)
				bu[--padd_start] = extra_c;
			bu[1] = '0';
			bu[2] = 'x';
			return (write(1, &bu[padd_start], i - padd_start) +
				write(1, &bu[ind], length - (1 - padd_start) - 2));
		}
	}
	bu[--ind] = 'x';
	bu[--ind] = '0';
	if (extra_c)
		bu[--ind] = extra_c;
	return (write(1, &bu[ind], BUFF_S - ind - 1));
}

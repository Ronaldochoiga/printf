#include "main.h"


/**
 * print_char - Prints a char
 * @types: List a of arg
 * @bu: Bu arr handle print
 * @f:  Calculates active f
 * @w: W
 * @pr: Pr specification
 * @s: S specifier
 * Return: num of chars p
 */
int print_char(va_list types, char bu[],
	int f, int w, int pr, int s)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, bu, f, w, pr, s));
}
/**
 *print_string - returns  chars to be printed
 * @types: List a of arg
 * @bu: Bu arr handle print
 * @f:  Calculates active f
 * @w: get w.
 * @pr: Pr specification
 * @s: S specifier
 * Return: num of chars p
 */
int print_string(va_list types, char bu[],
	int f, int w, int pr, int s)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(bu);
	UNUSED(f);
	UNUSED(w);
	UNUSED(pr);
	UNUSED(s);
	if (str == NULL)
	{
		str = "(null)";
		if (pr >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (pr >= 0 && pr < length)
		length = pr;

	if (w > length)
	{
		if (f & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = w - length; i > 0; i--)
				write(1, " ", 1);
			return (w);
		}
		else
		{
			for (i = w - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (w);
		}
	}

	return (write(1, str, length));
}

/**
 * print_percent - Prints a percent sign
 * @types: Lst of arg
 * @bu: Bu arr handle print
 * @f:  Calculates active f
 * @w: get w.
 * @pr: Pr specification
 * @s: S specifier
 * Return: num of chars p
 */
int print_percent(va_list types, char bu[],
	int f, int w, int pr, int s)
{
	UNUSED(types);
	UNUSED(bu);
	UNUSED(f);
	UNUSED(w);
	UNUSED(pr);
	UNUSED(s);
	return (write(1, "%%", 1));
}


/**
 * print_int - Print int
 * @types: Lst of arg
 * @bu: Bu arr handle print
 * @f:  Calculates active f
 * @w: get w.
 * @pr: Pr specification
 * @s: S specifier
 * Return: num of chars p
 */
int print_int(va_list types, char bu[],
	int f, int w, int pr, int s)
{
	int i = BUFF_S - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_s_number(n, s);

	if (n == 0)
		bu[i--] = '0';

	bu[BUFF_S - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		bu[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, bu, f, w, pr, s));
}


/**
 * print_binary - Prints an unsigned number
 * @types: Lst of arg
 * @bu: Bu arr handle print
 * @f:  Calculates active f
 * @w: get w.
 * @pr: Pr specification
 * @s: S specifier
 * Return: Numbers of char p.
 */
int print_binary(va_list types, char bu[],
	int f, int w, int pr, int s)
{
	unsigned int n, m, i, sm;
	unsigned int a[32];
	int co;

	UNUSED(bu);
	UNUSED(f);
	UNUSED(w);
	UNUSED(pr);
	UNUSED(s);

	n = va_arg(types, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sm = 0, co = 0; i < 32; i++)
	{
		sm += a[i];
		if (sm || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			co++;
		}
	}
	return (co);
}

#include "main.h"


/**
 * print_unsigned - Prints unsigned number
 * @types: List of arg
 * @bu: Bu arr to handle print
 * @f:  Calculates active f
 * @w: get w
 * @pr: Pr speccation
 * @s: S specer
 * Return: num of chars printed.
 */
int print_unsigned(va_list types, char bu[],
	int f, int w, int pr, int s)
{
	int i = BUFF_S - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_s_unsgnd(num, s);

	if (num == 0)
		bu[i--] = '0';

	bu[BUFF_S - 1] = '\0';

	while (num > 0)
	{
		bu[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, bu, f, w, pr, s));
}

/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: list of arg
 * @bu: Bu arr to handle print
 * @f:  Calculates active f
 * @w: get w
 * @pr: Pr speccation
 * @s: S specer
 * Return: num of chars printed
 */
int print_octal(va_list types, char bu[],
	int f, int w, int pr, int s)
{

	int i = BUFF_S - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(w);

	num = convert_s_unsgnd(num, s);

	if (num == 0)
		bu[i--] = '0';

	bu[BUFF_S - 1] = '\0';

	while (num > 0)
	{
		bu[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (f & F_HASH && init_num != 0)
		bu[i--] = '0';

	i++;

	return (write_unsgnd(0, i, bu, f, w, pr, s));
}

/**
 * print_hexadecimal - Prints an unsigned number
 * @types: list of arg
 * @bu: Bu arr to handle print
 * @f:  Calculates active f
 * @w: get w
 * @pr: Pr speccation
 * @s: S specer
 * Return: num of chars printed
 */
int print_hexadecimal(va_list types, char bu[],
	int f, int w, int pr, int s)
{
	return (print_hexa(types, "0123456789abcdef", bu,
		f, 'x', w, pr, s));
}

/**
 * print_hexa_upper - Prints an unsigned number
 * @types: list of arg
 * @bu: Bu arr to handle print
 * @f:  Calculates active f
 * @w: get w
 * @pr: Pr speccation
 * @s: S specer
 * Return: num of chars printed
 */
int print_hexa_upper(va_list types, char bu[],
	int f, int w, int pr, int s)
{
	return (print_hexa(types, "0123456789ABCDEF", bu,
		f, 'X', w, pr, s));
}

/**
 * print_hexa - Prints a hexadecimal
 * @types: list of arg
 * @map_to: Arr of values to map
 * @bu: Bu arr to handle print
 * @f:  Calculates active f
 * @flag_ch: Calculates active f
 * @w: get w
 * @pr: Pr speccation
 * @s: S specer
 * @s: S speccation
 * Return: num of chars printed
 */
int print_hexa(va_list types, char map_to[], char bu[],
	int f, char flag_ch, int w, int pr, int s)
{
	int i = BUFF_S - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(w);

	num = convert_s_unsgnd(num, s);

	if (num == 0)
		bu[i--] = '0';

	bu[BUFF_S - 1] = '\0';

	while (num > 0)
	{
		bu[i--] = map_to[num % 16];
		num /= 16;
	}

	if (f & F_HASH && init_num != 0)
	{
		bu[i--] = flag_ch;
		bu[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, bu, f, w, pr, s));
}

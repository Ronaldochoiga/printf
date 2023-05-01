#include "main.h"

/**
 * is_printable - checks whether printable
 * @c: character evaluated
 * Return: 1 or 0
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append ascii code
 * @bu: Arr
 * @i: startpoint of append
 * @ascii_code: code
 * Return: 3
 */
int append_hexa_code(char ascii_code, char bu[], int i)
{
	char mp[] = "0123456789ABCDEF";
	if (ascii_code < 0)
		ascii_code *= -1;

	bu[i++] = '\\';
	bu[i++] = 'x';

	bu[i++] = mp[ascii_code / 16];
	bu[i] = mp[ascii_code % 16];

	return (3);
}

/**
 * is_digit - checks where digit
 * @c: Characters evaluated
 * Return: 1 or 0
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_s_number - gives num whose s is converted
 * @num: Num casted
 * @s: Num s to be cated
 * Return: value of cas
 */
long int convert_s_number(long int num, int s)
{
	if (s == S_LONG)
		return (num);
	else if (s == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_s_unsgnd - gives specific s
 * @num: Num to cas
 * @s: Num indicating s
 * Return: value of cast
 */
long int convert_s_unsgnd(unsigned long int num, int s)
{
	if (s == S_LONG)
		return (num);
	else if (s == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

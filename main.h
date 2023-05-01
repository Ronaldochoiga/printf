#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_S 1024


#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16


#define S_LONG 2
#define S_SHORT 1


struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};





typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char bu[], int f, int w, int pr, int s);

int print_char(va_list types, char bu[],
	int f, int w, int pr, int s);
int print_string(va_list types, char bu[],
	int f, int w, int pr, int s);
int print_percent(va_list types, char bu[],
	int f, int w, int pr, int s);


int print_int(va_list types, char bu[],
	int f, int w, int pr, int s);
int print_binary(va_list types, char bu[],
	int f, int w, int pr, int s);
int print_unsigned(va_list types, char bu[],
	int f, int w, int pr, int s);
int print_octal(va_list types, char bu[],
	int f, int w, int pr, int s);
int print_hexadecimal(va_list types, char bu[],
	int f, int w, int pr, int s);
int print_hexa_upper(va_list types, char bu[],
	int f, int w, int pr, int s);

int print_hexa(va_list types, char map_to[],
char bu[], int f, char flag_ch, int w, int pr, int s);

int print_non_printable(va_list types, char bu[],
	int f, int w, int pr, int s);


int print_pointer(va_list types, char bu[],
	int f, int w, int pr, int s);

int get_f(const char *format, int *i);
int get_w(const char *format, int *i, va_list list);
int get_pr(const char *format, int *i, va_list list);
int get_s(const char *format, int *i);


int print_reverse(va_list types, char bu[],
	int f, int w, int pr, int s);

int print_rot13string(va_list types, char bu[],
	int f, int w, int pr, int s);

int handle_write_char(char c, char bu[],
	int f, int w, int pr, int s);
int write_number(int is_positive, int ind, char bu[],
	int f, int w, int pr, int s);
int write_num(int ind, char bff[], int f, int w, int pr,
	int length, char padd, char extra_c);
int write_pointer(char bu[], int ind, int length,
	int w, int f, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char bu[],
	int f, int w, int pr, int s);

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_s_number(long int num, int s);
long int convert_s_unsgnd(unsigned long int num, int s);

#endif 

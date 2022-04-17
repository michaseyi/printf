#ifndef _MAIN_
#define _MAIN_

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define BUFF_SIZE 1024
#define True 1
#define False 0
#define STAR -9

typedef int bool;

/**
 * struct extract - Holds the details on how to format an input
 * @sign: True if '+' is present else False
 * @space: True if [space] is present else False
 * @prefix: True if '#' is present else False
 * @left_indent: True if '-' is present else False
 * @fill_zero: True if '0' is present else False
 * @width: Holds width
 * @precision: Holds precision
 * @data_type: holds the data type
 * @bytes_read: holds the number of bytes read
 */

typedef struct extract
{
	bool sign;
	bool space;
	bool prefix;
	bool left_indent;
	bool fill_zero;
	int width;
	int precision;
	char data_type[2];
	int bytes_read;
} extract;

/**
 * fptr - typedef of a function pointer that returns a char *
 * takes in list, and data
 */

typedef char *(*fptr)(va_list list, extract data);

/**
 * struct funcs - holds a function name and a pointer to it
 * @name: function name
 * @f: pointer to the function
 */

typedef struct funcs
{
	char *name;
	fptr f;
} funcs;

fptr get_func(char *type);
bool check_if_valid(const char *str, extract *data, va_list list);
void reset_extract(extract *data);
int _putchar(char c);
int _printf(const char *format, ...);
int len_num(long int number, int base);
char *handle_prefix(char *str, char type);
char *handle_sign(char *str);
char *handle_space(char *str);
char *handle_precision(char *str, int prec_len, char character);
char *handle_left_indent(char *str, int width);
char *fill_zeros(char *str, int width, int position);
char *add_left_spaces(char *str, int width);
char hex_u(int num);
char hex_l(int num);
char char_num(int num);
void _print(char *str);
char *print_d(va_list list, extract data);
char *print_s(va_list list, extract data);
char *print_x(va_list list, extract data);
char *print_o(va_list list, extract data);

#endif

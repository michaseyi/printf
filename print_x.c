#include "main.h"

/**
 * print_x - handles printing of unsigned int in lowercase hexadecimal
 * @args: argument to call to get the value
 * @data: a struct that holds info about flags, width, precision
 * Return: The string generated
 */

char *print_x(va_list args, extract data)
{
	unsigned int number = va_arg(args, unsigned int);
	int len = len_num(number, 16), position = 0;
	char n, *str = malloc(sizeof(char) * (len + 1));

	str[len--] = '\0';
	if (data.prefix)
		position += 2;
	while (number)
	{
		n = hex_l(number % 16);
		number /= 16;
		str[len--] = n;
	}

	if (data.precision >= 0 && data.precision > (int)_strlen(str))
		str = handle_precision(str, data.precision, '0');
	if (data.prefix)
		str = handle_prefix(str, 'x');
	if (data.width > 0 && data.width > (int)_strlen(str))
	{
		if (data.left_indent)
			str = handle_left_indent(str, data.width);
		else if (data.precision >= 0)
			str = add_left_spaces(str, data.width);
		else if (data.fill_zero)
			str = fill_zeros(str, data.width, position);
		else
			str = add_left_spaces(str, data.width);
	}
	return (str);
}

/**
 * print_lx - handles printing of unsigned long int in lowercase hexadecimal
 * @args: argument to call to get the value
 * @data: a struct that holds info about flags, width, precision
 * Return: The string generated
 */

char *print_lx(va_list args, extract data)
{
	unsigned long int number = va_arg(args, unsigned long int);
	int len = len_num(number, 16), position = 0;
	char n, *str = malloc(sizeof(char) * (len + 1));

	str[len--] = '\0';
	if (data.prefix)
		position += 2;
	while (number)
	{
		n = hex_l(number % 16);
		number /= 16;
		str[len--] = n;
	}

	if (data.precision >= 0 && data.precision > (int)_strlen(str))
		str = handle_precision(str, data.precision, '0');
	if (data.prefix)
		str = handle_prefix(str, 'x');
	if (data.width > 0 && data.width > (int)_strlen(str))
	{
		if (data.left_indent)
			str = handle_left_indent(str, data.width);
		else if (data.precision >= 0)
			str = add_left_spaces(str, data.width);
		else if (data.fill_zero)
			str = fill_zeros(str, data.width, position);
		else
			str = add_left_spaces(str, data.width);
	}
	return (str);
}

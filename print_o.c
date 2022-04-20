#include "main.h"

/**
 * print_o - handles printing of unsigned int in octal
 * @args: argument to call to get the value
 * @data: a struct that holds info about flags, width, precision
 * Return: The string generated
 */

char *print_o(va_list args, extract data)
{
	unsigned int number = va_arg(args, unsigned int);
	int len, position = 0;
	char n, *str;

	if (number != 0)
	{
		len = len_num(number, 8);
		str = malloc(sizeof(char) * (len + 1));
		str[len--] = '\0';
		while (number)
		{
			n = hex_l(number % 8);
			number /= 8;
			str[len--] = n;
		}
	}
	else
	{
		str = malloc(sizeof(char) * 2);
		str[0] = char_num(0);
		str[1] = '\0';
		return (str);
	}
	if (data.prefix)
		position++;
	if (data.precision >= 0 && data.precision > (int)_strlen(str))
		str = handle_precision(str, data.precision, '0');
	if (data.prefix)
		str = handle_prefix(str, 'o');
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
 * print_lo - handles printing of unsigned int in octal
 * @args: argument to call to get the value
 * @data: a struct that holds info about flags, width, precision
 * Return: The string generated
 */

char *print_lo(va_list args, extract data)
{
	unsigned long int number = va_arg(args, unsigned long int);
	int len, position = 0;
	char n, *str;

	if (number != 0)
	{
		len = len_l(number, 8);
		str = malloc(sizeof(char) * (len + 1));
		str[len--] = '\0';
		while (number)
		{
			n = hex_l(number % 8);
			number /= 8;
			str[len--] = n;
		}
	}
	else
	{
		str = malloc(sizeof(char) * 2);
		str[0] = char_num(0);
		str[1] = '\0';
		return (str);
	}
	if (data.prefix)
		position++;
	if (data.precision >= 0 && data.precision > (int)_strlen(str))
		str = handle_precision(str, data.precision, '0');
	if (data.prefix)
		str = handle_prefix(str, 'o');
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

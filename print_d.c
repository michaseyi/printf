#include "main.h"

/**
 * print_d - handles printing numbers
 * @list: holds argument
 * @data: a struct that holds data on how to format
 * Return: pointer to formated string
 */

char *print_d(va_list list, extract data)
{
	int number = va_arg(list, int), dup_num = number;
	int len, position = 0;
	char n, *str;

	if (number != 0)
	{
		len = len_num(dup_num, 10);
		str = malloc(sizeof(char) * (len + 1));
		str[len--] = '\0';
		while (dup_num)
		{
			if (number < 0)
				n = char_num(-(dup_num % 10));
			else
				n = char_num(dup_num % 10);
			dup_num /= 10;
			str[len--] = n;
		}
	}
	else
	{
		str = malloc(sizeof(char) * 2);
		str[0] = char_num(0);
		str[1] = '\0';
	}
	if (data.sign || data.space || number < 0)
		position++;
	if (data.precision >= 0 && data.precision > (int)_strlen(str))
		str = handle_precision(str, data.precision, '0');
	if (number < 0)
		str = handle_sign(str, '-');
	if (data.sign && number >= 0)
		str = handle_sign(str, '+');
	if (data.space && !data.sign && number >= 0)
		str = handle_space(str);
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
 * print_ld - handles printing long numbers
 * @list: holds argument
 * @data: a struct that holds data on how to format
 * Return: pointer to formated string
 */

char *print_ld(va_list list, extract data)
{
	long int number = va_arg(list, long int), dup_num = number;
	int len, position = 0;
	char n, *str;

	if (number != 0)
	{
		len = len_num(dup_num, 10);
		str = malloc(sizeof(char) * (len + 1));
		str[len--] = '\0';
		while (dup_num)
		{
			if (number < 0)
				n = char_num(-(dup_num % 10));
			else
				n = char_num(dup_num % 10);
			dup_num /= 10;
			str[len--] = n;
		}
	}
	else
	{
		str = malloc(sizeof(char) * 2);
		str[0] = char_num(0);
		str[1] = '\0';
	}
	if (data.sign || data.space || number < 0)
		position++;

	if (data.precision >= 0 && data.precision > (int)_strlen(str))
		str = handle_precision(str, data.precision, '0');
	if (number < 0)
		str = handle_sign(str, '-');
	if (data.sign && number >= 0)
		str = handle_sign(str, '+');
	if (data.space && !data.sign && number >= 0)
		str = handle_space(str);
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

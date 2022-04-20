#include "main.h"

/**
 * print_p - Handles printing address
 * @args: list of arguments
 * @data: a struct that holds info about how to format
 * Return: pointer to a formated string
 */

char *print_p(va_list args, extract data)
{
	unsigned long int number = va_arg(args, unsigned long int);
	int len, position = 0;
	char n, *str;

	if (number != 0)
	{
		len = len_l(number, 16);
		str = malloc(sizeof(char) * (len + 1));
		str[len--] = '\0';
		while (number)
		{
			n = hex_l(number % 16);
			number /= 16;
			str[len--] = n;
		}
	}
	else
	{
		str = malloc(sizeof(char) * 5);
		_strcpy(str, "(nil)");
		return (str);
	}
	if (data.sign || data.space)
		position++;
	if (data.precision >= 0 && data.precision > (int)_strlen(str))
		str = handle_precision(str, data.precision, '0');
	str = handle_prefix(str, 'x');
	if (data.sign)
		str = handle_sign(str, '+');
	if (data.space && !data.sign)
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

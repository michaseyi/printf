#include "main.h"

/**
 * print_b - handles printing of unsigned int in binary
 * @args: argument to call to get the value
 * @data: a struct that holds info about flags, width, precision
 * Return: The string generated
 */

char *print_b(va_list args, __attribute__((unused))extract data)
{
	unsigned int number = va_arg(args, unsigned int);
	int len;
	char n, *str;

	if (number != 0)
	{
		len = len_num(number, 2);
		str = malloc(sizeof(char) * (len + 1));
		str[len--] = '\0';
		while (number)
		{
			n = hex_l(number % 2);
			number /= 2;
			str[len--] = n;
		}
	}
	else
	{
		str = malloc(sizeof(char) * 2);
		str[0] = char_num(0);
		str[1] = '\0';
	}
	return (str);
}

/**
 * print_lb - handles printing of unsigned long int in binary
 * @args: argument to call to get the value
 * @data: a struct that holds info about flags, width, precision
 * Return: The string generated
 */

char *print_lb(va_list args, __attribute__((unused))extract data)
{
	unsigned long int number = va_arg(args, unsigned long int);
	int len;
	char n, *str;

	if (number != 0)
	{
		len = len_l(number, 2);
		str = malloc(sizeof(char) * (len + 1));
		str[len--] = '\0';
		while (number)
		{
			n = hex_l(number % 2);
			number /= 2;
			str[len--] = n;
		}
	}
	else
	{
		str = malloc(sizeof(char) * 2);
		str[0] = char_num(0);
		str[1] = '\0';
	}
	return (str);
}

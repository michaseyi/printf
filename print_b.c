#include "main.h"

/**
 * print_b - handles printing of unsigned int in binary
 * @args: argument to call to get the value
 * @data: a struct that holds info about flags, width, precision
 * Return: The string generated
 */

char *print_b(va_list args, extract data)
{
	unsigned int number = va_arg(args, unsigned int);
	int len = len_num(number, 2), position = 0;
	char n, *str = malloc(sizeof(char) * (len + 1));

	str[len--] = '\0';
	if (data.prefix)
		position++;
	while (number)
	{
		n = hex_l(number % 2);
		number /= 2;
		str[len--] = n;
	}
	return (str);
}


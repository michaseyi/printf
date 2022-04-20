#include "main.h"

/**
 * print_S - Handles converting non printable characters in a string into the
 * hex equivalent
 * @list: where to get string
 * @data: stuct that holds info on how to modify the string
 * Return: pointer to modified string
 */

char *print_S(va_list list, __attribute__((unused)) extract data)
{
	char *str = va_arg(list, char *);
	int len;
	char *new_str;

	if (str == NULL)
	{
		new_str = malloc(sizeof(char) * 6);
		_strcpy(new_str, "(null)");
		return (new_str);
	}
	len = _strlen(str);
	new_str = malloc(sizeof(char) * (len + 1));
	new_str[len] = '\0';
	_strcpy(new_str, str);
	new_str = S(new_str);
	return (new_str);
}

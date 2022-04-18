#include "main.h"

/**
 * print_s - Handles printing of string
 * @list: where to get string
 * @data: stuct that holds info on how to modify the string
 * Return: pointer to modified string
 */

char *print_s(va_list list,  __attribute__((unused))extract data)
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
	return (new_str);
}

/**
 * print_c - Handles printing of characters
 * @list: where to get character
 * @data: struct that holds info on how to modify the string
 * Return: pointer to modified string
 */

char *print_c(va_list list, __attribute__((unused))extract data)
{
	char character = va_arg(list, int);
	int len = 1;
	char *str = malloc(sizeof(char) * (len + 1));

	str[len] = '\0';
	str[0] = character;
	return (str);
}

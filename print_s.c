#include "main.h"

/**
 * print_s - Handles printing of string
 * @list: where to get string
 * @data: stuct that holds info on how to modify the string
 * Return: pointer to modified string
 */

char *print_s(va_list list, extract data)
{
	char *str = va_arg(list, char *);
	int len = strlen(str);
	char *new_str = malloc(sizeof(char) * (len + 1));

	new_str[len] = '\0';
	strcpy(new_str, str);
	return (new_str);
}

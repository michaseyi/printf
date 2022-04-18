#include "main.h"

/**
 * handle_left_indent - add spaces at the end of @str till it has lenght width
 * @str: input string
 * @width: required width of the output string
 * Return: pointer to string with spaces at the end
 */

char *handle_left_indent(char *str, int width)
{
	int to_add = width - _strlen(str), i;
	char *new_str = malloc((width + 1) * sizeof(char));

	_strcpy(new_str, str);
	for (i = 0; i < to_add; i++)
		(new_str + _strlen(str))[i] = ' ';
	new_str[width] = '\0';
	free(str);
	return (new_str);
}

/**
 * fill_zeros - pads a string width '0' till it length equals @width
 * @str: input string
 * @width: required string
 * @position: position to start padding
 * Return: pointer to a string padded with zero
 */

char *fill_zeros(char *str, int width, int position)
{
	int to_add = width - _strlen(str), i;
	char *new_str = malloc((width + 1) * sizeof(char));

	for (i = 0; i < position; i++)
		new_str[i] = str[i];
	for (i = 0; i < to_add; position++, i++)
		new_str[position] = '0';
	_strcpy(new_str + position, str + (position - to_add));
	free(str);
	return (new_str);
}

/**
 * add_left_spaces - adds spaces to left side of a string till its length
 * equal @width
 * @str: input string
 * @width: required width
 * Return: pointer to a string with spaces on the left side
 */

char *add_left_spaces(char *str, int width)
{
	return (handle_precision(str, width, ' '));
}


/**
 * hex_u - returns the equvalent of a digit in uppercase hex
 * @num: input number
 * Return: char equivalent of @num in uppercase hex
 */

char hex_u(int num)
{
	if (num < 10)
		return ('0' + num);
	else
		return ('A' + num - 10);
}

/**
 * hex_l - returns the equvalent of a digit in lowercase hex
 * @num: input number
 * Return: char equivalent of @num in lowercase hex
 */

char hex_l(int num)
{
	if (num < 10)
		return ('0' + num);
	else
		return ('a' + num - 10);
}

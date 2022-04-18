#include "main.h"

/**
 * len_num - get lenght of a number in a given base
 * @number: input number
 * @base: base
 * Return: length of number in the given base
 */

int len_num(long int number, int base)
{
	if (!number)
		return (0);
	return (1 + len_num(number / base, base));
}

/**
 * handle_prefix - handles '#' to format string
 * @str: intput string
 * @type: type
 * Return: pointer to string width add prefix
 */

char *handle_prefix(char *str, char type)
{
	int len = (type == 'o') ? _strlen(str) + 2 : _strlen(str) + 3;
	char *prefix = (type == 'o') ? "0" : (type == 'x') ? "0x" : "0X";
	char *new_str = malloc(sizeof(char) * len);

	len = (type == 'o') ? 1 : 2;
	_strcpy(new_str, prefix);
	_strcpy(new_str + len, str);
	free(str);
	return (new_str);
}

/**
 * handle_sign - adds sign in front of a string
 * @str: input string
 * @sign: sign to add
 * Return: pointer to a sting with a '+' prefix
 */

char *handle_sign(char *str, char sign)
{
	int len = _strlen(str) + 2;
	char *new_str = malloc(sizeof(char) * len);

	new_str[0] = sign;
	_strcpy(new_str + 1, str);
	free(str);
	return (new_str);
}

/**
 * handle_space - adds a space in front of a string
 * @str: input string
 * Return: pointer to a string with a space prefix
 */

char *handle_space(char *str)
{
	int len = _strlen(str) + 2;
	char *new_str = malloc(sizeof(char) * len);

	new_str[0] = ' ';
	_strcpy(new_str + 1, str);
	free(str);
	return (new_str);
}

/**
 * handle_precision - makes a string a minimum of a @prec_len and fills
 * with @character
 * @str: input string
 * @prec_len: how long the output should be
 * @character: character to pad the string
 * Return: pointer to a string with width @prec_len padded with @character
 */

char *handle_precision(char *str, int prec_len, char character)
{
	int to_add = prec_len - _strlen(str), i;
	char *new_str = malloc((prec_len + 1) * sizeof(char));

	for (i = 0; i < to_add; i++)
		new_str[i] = character;
	_strcpy(new_str + i, str);
	free(str);
	return (new_str);
}

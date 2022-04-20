#include "main.h"

/**
 * H - coverts an unsigned char to a two digit hex number
 * @num: input number
 * Return: pointer to two digit hex
 */

char *H(unsigned char num)
{
	char *ret;
	char base[] = "0123456789ABCDEF";
	int n = 1;

	ret = malloc(sizeof(char) * 3);
	if (num < 16)
	{
		ret[0] = '0';
	}
	while (num)
	{
		ret[n] = base[num % 16];
		n--;
		num /= 16;
	}

	ret[2] = 0;
	return (ret);
}

/**
 * S - handles converting non printable characters to their hex equivalent
 * @str: input string
 * Return: pointert to string with zero non printable characters
 */

char *S(char *str)
{
	int i, count = 0, new_length;
	char *new_str, *hex;

	for (i = 0; str[i]; i++)
	{
		if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
			count++;
	}
	new_length = i + (3 * count);
	new_str = malloc(sizeof(char) * (new_length + 1));
	for (i = 0, count = 0; str[i]; i++, count++)
	{
		if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
		{
			_strcpy(new_str + count, "\\x");
			hex = H(str[i]);
			_strcpy(new_str + count + 2, hex);
			free(hex);
			count += 3;
			continue;
		}
		new_str[count] = str[i];
	}
	new_str[count] = 0;
	free(str);
	return (new_str);
}

#include "main.h"

/**
 * char_num - gets the ascii char of a num
 * @num: input number
 * Return: ascii char of @num
 */

char char_num(int num)
{
	return ('0' + num);
}

/**
 * _strcmp - compares two strings
 *  @s1: first string
 *  @s2: second string
 *  Return: 0 if the same else returns the difference
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
		{
			i++;
			continue;
		}
		return (s1[i] - s2[i]);
	}
	return (0);
}

/**
 * rev_string - reverse a string
 * @s: string to be reversed
 * Return: void
 */

void rev_string(char *s)
{
	int length, middle, i;
	char temp;

	length = _strlen(s);
	middle = length / 2;
	i = 0;

	while (middle)
	{
		temp = s[i];
		s[i] = s[length - 1 - i];
		s[length - 1 - i] = temp;
		middle--;
		i++;
	}
}

/**
 * rot13 - encodes a string using rot13
 * @s: input string
 * Return: encoded string
 */
char *rot13(char *s)
{
	int i;

	char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *ptr = s;

	while (*s)
	{
		for (i = 0; i <= 52; i++)
		{
			if (*s == rot13[i])
			{
				*s = ROT13[i];
				break;
			}
		}
		s++;
	}
	return (ptr);
}

/**
 * len_l - get lenght of a number in a given base
 * @number: input number
 * @base: base
 * Return: length of number in the given base
 */

int len_l(unsigned long number, int base)
{
	if (!number)
		return (0);
	return (1 + len_l(number / base, base));
}

/**
 * @file _print_x.c
 * @author Michael Adewole
 * @brief 
 * @version 0.1
 * @date 2022-04-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>

typedef int bool;
typedef struct extract
{
    bool sign;
    bool space;
    bool prefix;
    bool left_indent;
    bool fill_zero;
    int width;
    int precision;
    char data_type[4];
    int bytes_read;
} extract;

/**
 * len_lu - returns the length of a long unsigned number in base @base
 * @number: input number
 * @base: base
 * Return: length of number in base @base
 */

int len_lu(long unsigned number, int base)
{
    if (!number)
        return 0;
    return (1 + len_lu(number / base, base));
}

/**
 * hex - returns the equivalent of a number in hexadecimal
 * eg. input of int 10 will return char 'a'
 * @num: input number
 * return: char equavalent of @num in hexadecimal
 */

char hex(int num)
{
    if (num < 10)
        return ('0' + num);
    else
        return ('A' + num - 10);
}
/**
 * print_lx - Handles printing long unsigned int in uppercase hexadecimel
 * @data: a struct that holds info about flags, width, specifier
 * @buffer: where to store the generated string
 * Return: the number of characters printed
 */

int print_lx(extract data, char *buffer)
{
    long unsigned number = 15123;
    int len = len_lu(number, 16);
    char n, *str = malloc(sizeof(char) * (len + 1));
    str[len--] = '\0';

    while (number)
    {
        n = hex(number %  16);
        number /= 16;
        str[len--] = n;
    }
    printf("%s", str);
    return 0;
}


int main(void)
{
    int j = 2000l;
    char buffer[1024];
    extract data = {1,1,1,1,1,5,6,"lx",6};
    print_lx(data, buffer);
    return 0;

}


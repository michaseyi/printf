/**
 * @file get_func.c
 * @author Michael Adewole
 * @brief 
 * @version 0.1
 * @date 2022-04-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define True 1
#define False 0
typedef int bool;

/**
 * struct extract - Holds the details on how to format an input
 * @sign: True if + is present else False
 * @space: True if [space] is present else False
 * @prefix: True if # is present else False
 * @left_indent: True if - is present else False
 * @fill_zero: True if 0 is present else False
 * @width: Hold width
 * @precision: Holds precision
 * @data_type: holds the data type eg "ld" which is long int
 * @bytes_read: holds the number of bytes read
 */

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
 * @brief should return pointer to the valid function or return null if not found(for now its void)
 * shoud take in a string, and pointer to the extract datatype
 * Description: this function will be called once this symbol "%" is encountered
 * 
 * @param string 
 */

void get_func(char *string)
{
    int i, j, length_found = 0;
    extract data;
    const char flags[] = {'#', ' ', '-', '+', '0', '\0'};
    const char length[] = {'l', 'h', '\0'};
    const char specifier[] = {'s', 'c', 'x', 'X', 'd', 'i', 'o', 'b', 'r',
                              'R', 'p', 'u', 'S', '\0'};
    bool cont_search_len = True, is_found_specifier = False;

    /* Scans for flags */
    printf("Flags read: ");
    while (True)
    {
        j = 0;
        while (j < 5 && string[i])
        {
            if (string[i] == flags[j])
            {
                printf("%c ", string[i]);
                i++;
                break;
            }
            j++;
        }
        if (!flags[j] || !string[i])
        {
            break;
        }
    }
    printf("\n");

    /* Scans for width */
    printf("Width: ");
    if (string[i] && string[i] == '*')
    {
        /* Get width from arguments */
        i++;
    }
    else
    {
        while (string[i] && isdigit(string[i]))
        {
            /* Store the digits somewhere */
            printf("%c", string[i]);
            i++;
        }
    }
    printf("\n");

    /* Scans for precision */
    printf("Precision: ");
    if (string[i] && string[i] == '.')
    {
        i++;
        if (string[i] && string[i] == '*')
        {
            /* Get precision from arguments */
            i++;
        }
        else if (string[i] && isdigit(string[i]))
        {
            while (string[i] && isdigit(string[i]))
            {
                /* Store the digits somewhere */
                printf("%c", string[i]);
                i++;
            }
        }
        else
        {
            /* Handle invalid % call */
        }
    }
    printf("\n");

    /* Scans for length */
    printf("Length: ");
    while (cont_search_len)
    {
        for (j = 0; j < 2; j++)
        {
            if (string[i] && string[i] == length[j])
            {
                if (string[i] == 'h' && length_found == 1)
                {
                    cont_search_len = False;
                    break;
                }
                else if (string[i] == 'h' && length_found == 0)
                {
                    printf("%c", string[i]);
                    i++;
                    length_found++;
                    cont_search_len = False;
                    break;
                }
                else if (string[i] == 'l' && length_found == 1)
                {
                    printf("%c", string[i]);
                    i++;
                    length_found++;
                    cont_search_len = False;
                    break;
                }
                else 
                {
                    printf("%c", string[i]);
                    i++;
                    length_found++;
                    break;
                }
            }
        }
        if (!length[j])
            break;
    }
    printf("\n");

    /* Scans for specifier */
    for (j = 0; j < 13; j++)
    {
        if (string[i] == specifier[j])
        {
            is_found_specifier = True;
            break;
        }
    }
    
    if (is_found_specifier) 
        printf("Read %d character(s) and found type %c", i + 1, string[i]);
    else
        printf("Unmatched character %c after reading %d character(s)", string[i], i + 1);
}

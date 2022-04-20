#include "main.h"

/**
 * check_if_valid - checks if a % call is valid
 * @string: input string
 * @data: pointer to a extract data type
 * @list: va_list data type
 * Return: True if valid, False if not
 */

bool check_if_valid(const char *string, extract *data, va_list list)
{
	int i = 0, j = 0, length_found = 0, width = 0;
	int precision = 0, d_type = 0;
	char flags[] = "# -+0";
	char length[] = "lh";
	char specifier[] = "scxXdiobpurRS";
	bool cont_search_len = True, is_found_specifier = False;

	while (True)
	{
		j = 0;
		while (flags[j] && string[i])
		{
			if (string[i] == flags[j])
			{
				switch (string[i])
				{
				case ' ':
					data->space = True;
					break;
				case '-':
					data->left_indent = True;
					break;
				case '#':
					data->prefix = True;
					break;
				case '+':
					data->sign = True;
					break;
				case '0':
					data->fill_zero = True;
					break;
				}
				i++;
				break;
			}
			j++;
		}
		if (!flags[j])
			break;
	}

	if (string[i] && string[i] == '*')
	{
		data->width = STAR;
		i++;
	}
	else
	{
		while (string[i] && _isdigit(string[i]))
		{
			width = (width * 10) + (string[i] - '0');
			i++;
		}
		data->width = width;
	}

	if (string[i] && string[i] == '.')
	{
		i++;
		if (string[i] && string[i] == '*')
		{
			data->precision = STAR;
			i++;
		}
		else if (string[i] && _isdigit(string[i]))
		{
			while (string[i] && _isdigit(string[i]))
			{
			precision = (precision * 10) + (string[i] - '0');
			i++;
			}
			data->precision = precision;
		}
		else
		{
			/* do nothing */
		}
	}
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
				data->data_type[d_type++] = string[i];
				i++;
				length_found++;
				cont_search_len = False;
				break;
			}
			else if (string[i] == 'l' && length_found == 1)
			{
				cont_search_len = False;
				break;
			}
			else
			{
				data->data_type[d_type++] = string[i];
				i++;
				length_found++;
				break;
			}
			}
		}
		if (!length[j])
			break;
	}
	for (j = 0; specifier[j]; j++)
	{
		if (string[i] == specifier[j])
		{
			data->data_type[d_type] = string[i];
			is_found_specifier = True;
			break;
		}
	}
	data->bytes_read = i + 1;
	if (is_found_specifier)
	{
		if (data->width == STAR)
			data->width = va_arg(list, int);
		if (data->precision == STAR)
			data->precision = va_arg(list, int);
		return (True);
	}
	else
		return (False);
}

/**
 * get_func - gets the appopriate function based on @type
 * @type: name of function to get
 * Return: pointer to the function
 */

fptr get_func(char *type)
{
funcs funcs[27] = {{"s", print_s}, {"c", print_c}, {"x", print_x},
{"hx", print_x}, {"lx", print_lx}, {"o", print_o}, {"ho", print_o},
{"lo", print_lo}, {"d", print_d}, {"ld", print_ld}, {"hd", print_d},
{"X", print_X}, {"lX", print_lX}, {"hX", print_x}, {"u", print_u},
{"lu", print_lu}, {"hu", print_u}, {"i", print_d}, {"li", print_ld},
{"hi", print_d}, {"b", print_b}, {"p", print_p}, {"r", print_r},
{"R", print_R}, {"lb", print_lb}, {"hb", print_b}, {"S", print_S}};
	int i = 0;

	while (i < 27)
	{
		if (!_strcmp(type, funcs[i].name))
			break;
		i++;
	}
	return (funcs[i].f);
}

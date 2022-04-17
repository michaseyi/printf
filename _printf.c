#include "main.h"

/**
 * reset_extract - sets all properties of extract to false values
 * @data: pointer to a extract data type
 */

void reset_extract(extract *data)
{
	data->sign = False;
	data->space = False;
	data->prefix = False;
	data->left_indent = False;
	data->fill_zero = False;
	data->precision = -1;
	data->width = -1;
	data->bytes_read = 0;
	data->data_type[0] = '\0';
}

/**
 * _printf - prints out the expanded format to stdout
 * @format: intput format
 * Return: number of bytes written to stdout or -1 if it fails
 */

int _printf(const char *format, ...)
{
	int i = 0, n = 0;
	char buffer[BUFF_SIZE], *current;
	va_list args;
	fptr func;
	extract data;

	va_start(args, format);
	if (format == NULL || !strlen(format))
		return (0);
	reset_extract(&data);
	while (format[i])
	{
		reset_extract(&data);
		if (format[i] == '%')
		{
			if (check_if_valid(format + i + 1, &data, args))
			{
				i += data.bytes_read + 1;
				func = get_func(data.data_type);
				current = func(args, data);
				_print(current);
				n += strlen(current);
				free(current);
			}
			else if (format[i + 1] && format[i + 1] == '%')
			{
				_putchar(format[i]);
				n++;
				i += 2;
			}
			else
			{
				_putchar(format[i]);
				i++;
				n++;
			}
		}
		else
		{
			_putchar(format[i]);
			i++;
			n++;
		}
	}
	va_end(args);
	return (n);
}

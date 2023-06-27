#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: Format.
 * Return: Printed characters.
 */
int _printf(const char *format, ...)
{
	int y, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (y = 0; format && format[y] != '\0'; i++)
	{
		if (format[y] != '%')
		{
			buffer[buff_ind++] = format[y];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[y], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &y);
			width = get_width(format, &y, list);
			precision = get_precision(format, &y, list);
			size = get_size(format, &y);
			++y;
			printed = handle_print(format, &y, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints buffer contents where it exists.
 * @buffer: Array of characters.
 * @buff_ind: Index at which next characters are added, represents length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

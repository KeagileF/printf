#include "main.h"

/**
 * handle_width - A func that calcs the width
 * @format: Formatted string to print the arguments.
 * @i: A List of arguments to be printedd.
 * @list: list
 *
 * Return: width.
 */
int handle_width(const char *format, int *i, va_list list)
{
	int curr_i;
	int width = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (width);
}





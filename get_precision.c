#include "main.h"

/**
 * get_precision – A func that calcs Printing precisionn
 * @format: Formatted string in which to print the arguments
 * @y: List of arguments to be printed.
 * @list: List of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *y, va_list list)
{
	int curr_y = *y + 1;
	int precision = -1;

	if (format[curr_y] != '.')
		return (precision);

	precision = 0;

	for (curr_y += 1; format[curr_y] != '\0'; curr_y++)
	{
		if (digit(format[curr_y]))
		{
			precision *= 10;
			precision += format[curr_y] - '0';
		}
		else if (format[curr_y] == '*')
		{
			curr_y++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*y = curr_y - 1;

	return (precision);
}

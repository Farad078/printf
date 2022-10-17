#include "main.h"

/**
 * _printf - check main
 * Description: a function that produces output according to a format.
 * @format: a pointer to character
 * Return: returns an integer
 */

int _printf(const char *format, ...)
{
	int i;
	char *x;
	int k = 0;
	int num_arg = strlen(format);
	va_list args;

	va_start(args, format);

	for (i = 0; i < num_arg; i++)
	{
		if (format[i] != '%')
		{
			k = i;
			k--;
			if (format[k] != '%')
			{
				printf("%c", format[i]);
				k = 0;
			}
			else
				continue;
		}
		if (format[i] == '%')
		{
			k = i;
			k++;
			if (format[k] == 'c')
			{
				char z = va_arg(args, int);
				printf("%c", z);
				k = 0;
			}
		}
		if (format[i] == '%')
		{
			k = i;
			k++;
			if (format[k] == 's')
			{
				x = va_arg(args, char *);
				printf("%s", x);
				k = 0;
			}
		}
		if (format[i] == '%')
		{
			k = i;
			k++;
			if (format[k] == 'd')
			{
				int y = va_arg(args, int);
				printf("%d", y);
				k = 0;
			}
		}
		if (format[i] == '%')
		{
			k = i;
			k++;
			if (format[k] == 'i')
			{
				int y = va_arg(args, int);
				printf("%i", y);
				k = 0;
			}
		}
	}
	return (i);
}

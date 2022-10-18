#include "main.h"

/**
 * check_sc - check here
 * Description: check for a string or character.
 * @x: input to character
 * @i: input integer
 * @args: input va_list argument
 * Return: returns Nothing
 */

void check_sc(const char *x, int i, va_list args)
{
	int k;

	if (x[i] == '%')
	{
		k = i;
		k++;
		if (x[k] == 'c')
		{
			char z = va_arg(args, int);

			printf("%c", z);
			k = 0;
		}
	}
	if (x[i] == '%')
	{
		k = i;
		k++;
		if (x[k] == 's')
		{
			char *y = va_arg(args, char *);

			printf("%s", y);
			k = 0;
		}
	}
}

/**
 * check_id - check here
 * Description: check for a string or character.
 * @x: input to character
 * @i: input integer
 * @args: input va_list argument
 * Return: returns Nothing
 */

void check_id(const char *x, int i, va_list args)
{
	int k;

	if (x[i] == '%')
	{
		k = i;
		k++;
		if (x[k] == 'd')
		{
			int y = va_arg(args, int);

			printf("%d", y);
			k = 0;
		}
	}
	if (x[i] == '%')
	{
		k = i;
		k++;
		if (x[k] == 'i')
		{
			int y = va_arg(args, int);

			printf("%i", y);
			k = 0;
		}
	}
}

/**
 * _printf - check main
 * Description: a function that produces output according to a format.
 * @format: a pointer to character
 * Return: returns an integer
 */

int _printf(const char *format, ...)
{
	int i;
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
		check_sc(format, i, args);
		check_id(format, i, args);
	}
	return (i);
}

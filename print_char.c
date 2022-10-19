#include "main.h"

/**
 * _print_char - print out the character c to stdout
 * @z: The character to print
 *
 * Return: success return 1.
 * On error, -1 is returned, and error is set appropriately.
 */
int _print_char(char z)
{
	return (write(1, &z, 1));
}

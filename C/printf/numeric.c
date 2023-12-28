#include "main.h"

/**
 * number_f - Format a (un)signed number and store it in a buffer.
 *  This function handles the decimal base
 * @buffer: The buffer to store the formatted number.
 * @args: The variable arguments list containing the number.
 * @idx: The current index in the buffer.
 * @F: The format specifier.
 *
 * Return: The number of characters added to the buffer.
 */

int number_f(char *buffer, va_list args, int idx, char F)
{
	char *type_c = "di", *tmp;
	int i, sign = 0;
	long int number;
	unsigned long n;

	for (i = 0; type_c[i]; i++)
	{
		if (type_c[i] == F)
			break;
	}
	number = va_arg(args, int);

	if (number < 0)
		n = -1 * number, sign = 1;
	else
		n = number;

	tmp = inToStr(n, i, sign);

	for (i = 0; tmp[i]; i++)
		buffer[idx++] = tmp[i];

	free(tmp);
	return (i);
}

/**
 * number_u - Format a unsigned number and store it in a buffer.
 *  This function handles the binary, hexa and octa bases
 * @buffer: The buffer to store the formatted number.
 * @args: The variable arguments list containing the number.
 * @idx: The current index in the buffer.
 * @F: The format specifier.
 *
 * Return: The number of characters added to the buffer.
 */

int number_u(char *buffer, va_list args, int idx, char F)
{
	char *type_c = "bxXou", *tmp;
	int i, number;

	for (i = 0; type_c[i]; i++)
	{
		if (type_c[i] == F)
			break;
	}
	tmp = inToStr(va_arg(args, unsigned long), i + 2, 0);

	for (i = 0; tmp[i]; i++)
		buffer[idx++] = tmp[i];

	free(tmp);
	return (i);
}

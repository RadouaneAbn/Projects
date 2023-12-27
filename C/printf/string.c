#include "main.h"

/**
 * char_f - Format a character and store it in a buffer.
 * @buffer: The buffer to store the formatted character.
 * @args: The variable arguments list containing the character.
 * @idx: The current index in the buffer.
 * @F: The format specifier.
 *
 * Return: The number of characters added to the buffer.
 */

int char_f(char *buffer, va_list args, int idx, char F)
{
	if (!F)
		exit(-1);

	char ch = va_arg(args, int);

	buffer[idx] = ch;
	return (1);
}

/**
 * string_f - Format a string and store it in a buffer.
 * @buffer: The buffer to store the formatted string.
 * @args: The variable arguments list containing the string.
 * @idx: The current index in the buffer.
 * @F: The format specifier.
 *
 * Return: The number of characters added to the buffer.
 */

int string_f(char *buffer, va_list args, int idx, char F)
{
	size_t i;
	char *str = va_arg(args, char *);

	if (!str)
		str = "(null)";

	for (i = 0; str[i]; i++)
		buffer[idx++] = str[i];

	return (i);
}

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
	char *type_c = "b", *tmp;
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

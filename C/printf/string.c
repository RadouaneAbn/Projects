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
 * string_s - Format a string and store it in a buffer.
 *	replace special characters with their ascii value in hexadecimal.
 * @buffer: The buffer to store the formatted string.
 * @args: The variable arguments list containing the string.
 * @idx: The current index in the buffer.
 * @F: The format specifier.
 *
 * Return: The number of characters added to the buffer.
 */

int string_s(char *buffer, va_list args, int idx, char F)
{
	int i;
	char *str = va_arg(args, char *);
	char *hexStr = "\\x0", *tmp;
	int n_char, j, str_ascii, idx_start = idx;

	if (!str)
		str = "\\x00";

	for (i = 0; str[i]; i++)
	{
		n_char = 2, str_ascii = str[i];
		if (str_ascii < 32 || str_ascii >= 127)
		{
			if (str_ascii < 16)
				n_char++;

			for (j = 0; j < n_char; j++)
				buffer[idx++] = hexStr[j];

			tmp = inToStr(str_ascii, 4, 0);
			for (j = 0; tmp[j]; j++)
				buffer[idx++] = tmp[j];

			if (tmp)
				free(tmp);
		}
		else
			buffer[idx++] = str[i];
	}
	return (idx - idx_start);
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



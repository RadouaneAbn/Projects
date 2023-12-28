#include "main.h"

void prototype(void);

/**
 * _printf - This function prints a string
 * @format: The string
 *
 * Return: 0 if successed, -1 if failed
 */

int _printf(const char *format, ...)
{
	char buffer[BUF_SIZE], fl;
	va_list args;
	int i, det, fp = 0, tmp;
	int buf_i = 0, size = 11;
	flag_t data[] = {
		{'s', string_f}, {'S', string_s}, {'c', char_f}, {'d', number_f},
		{'i', number_f}, {'b', number_u}, {'x', number_u}, {'X', number_u},
		{'o', number_u}, {'u', number_u}, {'p', address}
	};


	if (!format)
		return (-1);

	va_start(args, format);

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			else if (format[i + 1] == '%')
				i++;
			else
			{
				tmp = check_elegible(format, i + 1);
				if (tmp != -1)
				{
					i = tmp;
					for (fp = 0; fp < size; fp++)
					{
					if (format[i] == data[fp].csp)
					{
						buf_i += data[fp].f(buffer, args, buf_i, data[fp].csp);
						break;
					}
					}
					continue;
				}
			}
		}
		buffer[buf_i++] = format[i];
	}

	write(STDOUT_FILENO, buffer, buf_i);
	return (buf_i);
}

/**
 * check_elegible - This function checks if a format specifier is elegible
 *  for string formating
 * @format: The string
 * @i: the index of the character after '%'
 *
 * Return: a index of the format specifier (in case of spaces)
 */

int check_elegible(const char *format, int i)
{
	char *flags = "csSdibxXoup";
	int j;

	while (format[i] == ' ')
		i++;

	for (j = 0; flags[j]; j++)
	{
		if (format[i] == flags[j])
			return (i);
	}

	return (-1);
}

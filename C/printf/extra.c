#include "main.h"

/**
 * inToStr - This function converts a number into a string
 *  to be added into the buffer
 * @n: The number without the sign if it exists
 * @type: The base to be used in the convertion
 * @sign: The sign if it exists
 *
 * Return: a string representaion of the number
 */

char *inToStr(unsigned long n, int type, int sign)
{
	char tmp[1024], *result;
	int i, r = 0;
	int base[] = {DEC, DEC, BIN};

	if (n == 0)
		return (strdup("0"));

	for (i = 0; n; i++, n /= base[type])
		tmp[i] = n % base[type] + '0';

	result = malloc((sign + 1 + i--) * sizeof(char));
	if (result == NULL)
		exit(-1);

	if (sign)
		result[r++] = '-';

	for (; i >= 0; i--)
		result[r++] = tmp[i];
	result[r] = '\0';

	return (result);
}

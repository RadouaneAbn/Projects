#include "main.h"

/**
 * inToStr - This function converts a number at any base into a string
 *  to be added into the buffer
 * @n: The number without the sign if it exists
 * @type: The base to be used in the convertion
 * @sign: The sign if it exists
 *
 * Return: a string representaion of the number
 */

char *inToStr(unsigned long n, int type, int sign)
{
	char tmp[1024], *result, hex_n = 'a';
	int i, r = 0, n_tmp;
	int base[] = {DEC, DEC, BIN, HEX, HEX, OCT, DEC};

	if (n == 0)
		return (strdup("0"));

	if (type == 4)
		hex_n = 'A';

	for (i = 0; n; i++, n /= base[type])
	{
		n_tmp = n % base[type];
		if (n_tmp > 9)
			tmp[i] = hex_n + (n_tmp - 10);
		else
			tmp[i] = '0' + n_tmp;
	}

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

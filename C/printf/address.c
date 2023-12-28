#include "main.h"

/**
 * address - This function handles the address of pointer
 * @buffer: The buffer to store the formatted number.
 * @args: The variable arguments list containing the number.
 * @idx: The current index in the buffer.
 * @F: The format specifier.
 *
 * Return: The number of characters added to the buffer.
 */

int address(char *buffer, va_list args, int idx, char F)
{
	int i = idx;
	void *p = va_arg(args, void *);
	unsigned long int addr = (unsigned long int)p;
	char *addr_hexs;

	if (!p)
		idx += strcnt(buffer, idx, "(nil)");
	else
	{
		addr_hexs = inToStr(addr, 3, 0);
		idx += strcnt(buffer, idx, "0x");
		idx += strcnt(buffer, idx, addr_hexs);

		if (addr_hexs)
			free(addr_hexs);
	}
	return (idx - i);
}

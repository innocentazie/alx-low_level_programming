#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index.
 * @n: unsigned long int input.
 * @index: index of the bit.
 *
 * Return: value of the bit or -1 if index exceeds the bit range.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= 64)
		return (-1);

	if (n == 0 && index < 64)
		return (0);

	unsigned int i;

	for (i = 0; i <= 63; n >>= 1, i++)
	{
		if (index == i)
			return (n & 1);
	}

	return (-1);
}


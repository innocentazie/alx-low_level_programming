#include "main.h"

/**
 * flip_bits - returns the number of bits needed to flip
 * to get from one number to another.
 * @n: number one.
 * @m: number two.
 *
 * Return: number of bits.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int nbits = 0;

	while (n || m)
	{
		if ((n & 1) != (m & 1))
			nbits++;
		n >>= 1;
		m >>= 1;
	}

	return (nbits);
}


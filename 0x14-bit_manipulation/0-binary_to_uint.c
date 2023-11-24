#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @b: string containing the binary number.
 *
 * Return: the converted unsigned int value or 0 if conversion fails.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int uint_val = 0;
	int len = 0, base_two = 1;

	if (!b)
		return (0);

	for (len = 0; b[len] != '\0'; len++)
		;

	for (len--; len >= 0; len--, base_two *= 2)
	{
		if (b[len] != '0' && b[len] != '1')
			return (0);

		if (b[len] == '1')
			uint_val += base_two;
	}

	return (uint_val);
}


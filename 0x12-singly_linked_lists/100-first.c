#include <stdio.h>

/**
 * bmain - function executed before main.
 *
 * Description: this function is executed before main().
 * It prints a quote.
 *
 * Return: void.
 */
void __attribute__ ((constructor)) bmain()
{
	printf("You're beat! and yet, you must allow");
	printf(",\nI bore my house upon my back!\n");
}


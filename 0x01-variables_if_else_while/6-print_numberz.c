#include <stdio.h>
/**
 * main - a program that prints all single digit numbers of base 10
 * starting from 0.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int a;

	for (a = 0; a <= 9; a++)
	{
		putchar('0' + a);
	}

	putchar('\n');

	return (0);
}

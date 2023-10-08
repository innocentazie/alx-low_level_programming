#include <stdio.h>
/**
 * main - a program that prints all the numbers of base 16 in lowercase
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char base_16;

	for (base_16 = 48; base_16 < 58; base_16++)
	{
		putchar(base_16);
	}
	for (base_16 = 97; base_16 < 103; base_16++)
	{
		putchar(base_16);
	}

	putchar('\n');

	return (0);
}

#include <stdio.h>
/**
 * main - a program that prints the alphabet in lowercase,
 * an then in uppercae, followed by a new line.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char alphbt = 'a';

	while (alphbt <= 'z')
	{
		putchar(alphbt);
		alphbt++;
	}

	alphbt = 'A';

	while (alphbt <= 'Z')
	{
		putchar(alphbt);
		alphbt++;
	}

	putchar('\n');

	return (0);
}

#include <stdio.h>
/**
 * main - a program that prints all single digit numbers of base 10
 * starting from 0.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int a = 0;

	while (a <= 9)
	{
		printf("%d", a);
		a++;
	}

	printf("\n");

	return (0);
}


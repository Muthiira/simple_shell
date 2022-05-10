#include <stdio.h>

/**
 * main - prints all arguments , without using ac
 * @ac: number of commandline arguments
 * @av: array of commandline arguments
 * 
 * Return: 0 Always.
 */

int main(int ac, char **av)
{
	int i;

	for (i = 0; av[i] != NULL; i++)
		printf("%s\n", av[i]);

	return (0);
}

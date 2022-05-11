#include <sys/types.h>
#include <unistd.h>
#inclue <stdio.h>

/**
 * main - fork example
 *
 * Return: 0
 */
int main(void)
{
	printf("child1: %u\n", fork());;
	printf("child2: %u\n", fork());;

	printf("pid: %u, ppid: %u\n", getpid(), getppid());

	return (0);
}

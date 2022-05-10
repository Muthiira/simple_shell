#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


/**
 * main - PID and PPID
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t pid, ppid;

    pid = getpid();
	ppid = getppid();

    printf("%u\n", ppid);
	printf("%u\n", pid);
    return (0);
}

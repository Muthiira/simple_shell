#include "main.h"
/**
 * main-displays prompt
 * @argc: number of arguements
 * @argv: arguements to be printed
 *
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	char **tokens;
	char *line;
	int status;
	struct stat st;
	(void)argc;

	signal(SIGINT, ctrl_c);
	if (fstat(0, &st) == -1)
		perror("fstat");
	status = 1;
	do {
		print_prompt();
		line = read_line();
		if (_strcmp(line, "\n") == 0)
		{
			tokens = NULL;
			free(line);
			continue;
		}
		get_history(line);
		tokens = _strtotokens(line);
		if (tokens[0] == NULL)
		{
			free(tokens);
			free(line);
			continue;
		}
/*handle exit invokation*/
		if (_strcmp(tokens[0], "exit") == 0)
		{
			shell_exit(tokens, line);
		}
		else
		{
			status = _execute(tokens, line, argv[0]);
		}
		free(line);
		free(tokens);
	} while (status == 1);
	return (status);
}

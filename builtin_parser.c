#include "main.h"

/**
 *builtin_parser - parses builtin programs
 *@tokens:split tokens from stdin
 *Return:0 - success,1 otherwise
 */
int builtin_parser(char **tokens)
{
/*cd handling*/
	if (_strcmp(*tokens, "cd") == 0)
	{
		return (_cd(tokens));
	}
/*user invokes env*/
	else if (_strcmp(*tokens, "env") == 0)
	{
		return (shell_environ());
	}
/*user invokes setenv*/
	else if (_strcmp(*tokens, "setenv") == 0)
	{
/*check if user inputs it in the form: setenv var_name var_value*/
		if (tokens[1] && tokens[2])
		{
			_setenv(tokens[1], tokens[2]);
			return (0);
		}
		printf("Usage: setenv var_name var_value\n");
		return (0);
	}
	else if (_strcmp(*tokens, "unsetenv") == 0)
	{
		if (tokens[1])
		{
			_unsetenv(tokens[1]);
			return (0);
		}
		printf("Usage: unsetenv VAR_NAME\n");
		return (0);
	}
	else if (strcmp(*tokens, "history") == 0)
	{
		return (display_history());
	}
	return (1);
}

#include "main.h"

/**
 * main - splits strings
 * @ac: number of arguments
 * @argv: array of arguments
 * @env: environment variables
 *
 * Return: Always 0
 */

int main(int ac, char **argv, char **env)
{
	char *av[1024];
	char *buffer = NULL;
	int status = 0;

	while (ac)
	{
		if (prompt_x(&buffer) == -1)
			return (status);
		get_command(buffer, av);
		if (av[0] == NULL)
		{
			free_buffer_av(buffer, av);
			continue;
		}
		exit_x(av, buffer, status);
		if (strcmp(av[0], "env") == 0)
		{
			free_buffer_av(buffer, av);
			print_env_x(env);
			continue;
		}
		if (getenv("PATH") != NULL)
			which_x(av);
		status = file_missing_error(av[0], argv[0]);
		if (status == 127)
		{
			free_buffer_av(buffer, av);
			continue;
		}
		status = fork_exec(av, env, buffer);
	}
	return (0);
}

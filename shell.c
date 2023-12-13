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

	while (ac)
	{
		if (prompt_x(&buffer) == -1)
			return (0);
		get_command(buffer, av);
		if (av[0] == NULL)
		{
			free_buffer_av(buffer, av);
			continue;
		}
		exit_x(av[0]);
		which_x(av);
		if (file_missing_error(av[0], argv[0]) == -1)
		{
			free_buffer_av(buffer, av);
			continue;
		}
		fork_exec(av, env, buffer);
	}
	return (0);
}

#include "main.h"

/**
 * fork_exec - fork and execute
 * @av: list of tokens of command
 * @env: environment variables
 * @buffer: getline buffer
 *
 * Return: 1 of error, 0 otherwise
*/

int fork_exec(char **av, char **env, char *buffer)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("Error: ");
		return (1);
	}
	if (pid == 0)
	{
		if (execve(av[0], av, env) == -1)
			perror("Error: ");
	}
	else
	{
		free_buffer_av(buffer, av);
		wait(&status);
	}
	return (status);
}

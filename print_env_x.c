#include "main.h"

/**
 * print_env_x - prints the environment
 * @env: the environment
 *
 * Return: Always 0.
 */

int print_env_x(char **env)
{
	unsigned int i;

	i = 0;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}

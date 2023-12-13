#include "main.h"

/**
 * which_x - check if command is in path
 * @av: array of commands
 *
 * Return: first path containing the command
*/

char **which_x(char **av)
{
	char *path_copy = NULL, *token, *pathname = NULL, *filename;
	struct stat st;
	size_t path_len, filename_len, total_len;

	filename = malloc(sizeof(char) * (strlen(av[0]) + 2));
	strcpy(filename, "/");
	strcat(filename, av[0]);
	path_copy = strdup(getenv("PATH"));
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		path_len = strlen(token);
		filename_len = strlen(filename);
		total_len = path_len + filename_len;
		pathname = malloc(total_len + 2);
		if (pathname == NULL)
		{
			perror("malloc");
			free(filename);
			return (NULL);
		}
		strcpy(pathname, token);
		strcat(pathname, filename);
		if (stat(pathname, &st) == 0)
		{
			free(av[0]);
			av[0] = pathname;
			free(path_copy);
			free(filename);
			return (av);
		}
		free(pathname);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	free(filename);
	return (av);
}

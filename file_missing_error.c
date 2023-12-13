#include "main.h"

/**
 * file_missing_error - check if file is present
 * @arg: the filename
 * @exec_name: the shell executable name
 *
 * Return: 0 if present, -1 if missing
*/

int file_missing_error(char *arg, char *exec_name)
{
	struct stat st;

	if (stat(arg, &st) == -1)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", exec_name, arg);
		return (127);
	}
	return (0);
}

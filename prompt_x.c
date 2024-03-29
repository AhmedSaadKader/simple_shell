#include "main.h"

/**
 * prompt_x - displays prompt
 * @buffer: getline buffer
 *
 * Return: -1 if end of line
*/

int prompt_x(char **buffer)
{
	int interactive_mode;
	size_t n = 0;
	ssize_t x = 0;

	interactive_mode = isatty(STDIN_FILENO);
	if (interactive_mode)
		write(STDOUT_FILENO, "$ ", 2);
	x = getline(buffer, &n, stdin);
	if (x == -1)
	{
		free(*buffer);
		*buffer = NULL;
		return (-1);
	}
	return (0);
}

#include "main.h"

/**
 * exit_x - exits the shell
 * @arg: exit argument
 * @buffer: the string to free if exit
 * @status: the status
*/

void exit_x(char **arg, char *buffer, int status)
{
	if (strcmp(arg[0], "exit") == 0)
	{
		free_buffer_av(buffer, arg);
		exit(status);
	}
}

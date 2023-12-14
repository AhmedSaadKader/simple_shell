#include "main.h"

/**
 * exit_x - exits the shell
 * @arg: exit argument
 * @buffer: the string to free if exit
 * @status: the status
 * @exec_name: name of executable file
*/

void exit_x(char **arg, char *buffer, int status, char *exec_name)
{
	if (strcmp(arg[0], "exit") == 0)
	{
		if (arg[1])
		{
			if (strcmp(arg[1], "0") == 0)
			{
				free_buffer_av(buffer, arg);
				exit(0);
			}
			if (status == 512)
				exit(2);
			status = atoi(arg[1]);
			if (status == 0)
			{
				fprintf(stderr, "%s: 1: %s: Illegal number: %s\n"
				, exec_name, arg[0], arg[1]);
				free_buffer_av(buffer, arg);
				exit(2);
			}
			if (status < 0)
			{
				fprintf(stderr, "%s: 1: %s: Illegal number: %d\n"
				, exec_name, arg[0], status);
				free_buffer_av(buffer, arg);
				exit(2);
			}
			free_buffer_av(buffer, arg);
			exit(status);
		}
		if (status == 512)
			status = 2;
		free_buffer_av(buffer, arg);
		exit(status);
	}
}

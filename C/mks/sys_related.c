#include "header.h"

/**
 * chmod_file - This fucntion gives a file rwxr-xr-x right
 * @name: The name of the file
 */

void chmod_file(const char *name)
{
	if (chmod(name, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH) == -1)
		err(CHMOD, name);
}

/**
 * run_cmd - This function build and runs linux command
 * @cmd: the program to run
 * @name: the argument(s) of that command
 */

void run_cmd(const char *cmd, const char *name)
{
	const char *format = "%s %s";
	char executed_cmd[1024];

	/*<-- Build the command 'vim + name' -->*/
	snprintf(executed_cmd, sizeof(executed_cmd), format, cmd, name);
	/*<-- run the command -->*/
	if (system(executed_cmd))
		err(EXEC, executed_cmd);
}

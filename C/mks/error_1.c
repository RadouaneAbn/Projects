#include "header.h"

/**
 * err - This function handels the errors of the program
 * @n: the error code Example: 111 >>> usage error
 * @name: the name of the program or the file, based on the error
 */

void err(int n, const char *name)
{
	switch (n)
	{
		case USAGE: /*<-- usage error -->*/
			usage_msg(name);
			break;
		case OPTION: /*<-- option/ flag error -->*/
			option_msg(name);
			break;
		case READ: /*<-- read file error -->*/
			read_msg(name);
			break;
		case CHMOD: /*<-- chmod error -->*/
			chmod_msg(name);
			break;
		case EXEC: /*<-- command execution error -->*/
			exec_msg(name);
			break;
		case OPEN: /*<-- open file error -->*/
			open_msg(name);
			break;
		case NOFILE: /*<-- file doesn't exist error -->*/
			nofile_msg(name);
			break;
		case CREATE: /*<-- create file error -->*/
			create_msg(name);
			break;
		default:
			exit(EXIT_FAILURE);
	}
}

/**
 * create_msg - This function diplays an error message in stderr
 * @name: The name of the file
 */

void create_msg(const char *name)
{
	fprintf(stderr, "%s: could not create file\n", name);
	exit(1);
}

/**
 * usage_msg - This function diplays an error message in stderr
 * @name: The name of the program
 */

void usage_msg(const char *name)
{
	fprintf(stderr,
	"Usage:  %s [OPTION] FILE...\n        %s FILE...\n", name, name);
	fprintf(stderr, "Try 'mks --help' for more information.\n");
	exit(1);
}

/**
 * option_msg - This function diplays an error message in stderr
 * @name: The OPTION/flag
 */

void option_msg(const char *name)
{
	fprintf(stderr,
	"mks: bad option '%s'\n    option requires an argument -- '-b'\n", name);
	fprintf(stderr, "Try 'mks --help' for more information.\n");
	exit(EXIT_FAILURE);
}

/**
 * read_msg - This function diplays an error message in stderr
 * @name: The name of the file
 */

void read_msg(const char *name)
{
	fprintf(stderr,
	"%s: No such file or you don't have the rights to read this file\n",
	name);
	exit(EXIT_FAILURE);
}

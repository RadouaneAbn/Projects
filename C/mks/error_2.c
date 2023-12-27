#include "header.h"

/**
 * chmod_msg - This function diplays an error message in stderr
 * @name: The name of the file
 */

void chmod_msg(const char *name)
{
	fprintf(stderr,
	"chmod: Operation not permitted -- '%s' does not exist\n", name);
	fprintf(stderr, "       or you don't have the rights to change it's mode.\n");
	exit(EXIT_FAILURE);
}

/**
 * exec_msg - This function diplays an error message in stderr
 * @name: The command
 */

void exec_msg(const char *name)
{
	fprintf(stderr, "something is wrong with this command '%s'\n", name);
	exit(EXIT_FAILURE);
}

/**
 * open_msg - This function diplays an error message in stderr
 * @name: The name of the file
 */

void open_msg(const char *name)
{
	fprintf(stderr, "%s: No such file or directory\n", name);
	exit(EXIT_FAILURE);
}

/**
 * nofile_msg - This function diplays an error message in stderr
 * @name: The name of the file
 */

void nofile_msg(const char *name)
{
	fprintf(stderr, "%s: missing file operand\n", name);
	fprintf(stderr, "Try 'mks --help' for more information.\n");
	exit(EXIT_FAILURE);
}

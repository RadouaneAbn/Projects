#include "header.h"

/**
 * help - This function handles the '--help' and '--version' option\flags
 * @n: The option code 222 >>> help && 333 >>> version
 */

void help(int n)
{
	if (n == HELP)
		help_msg();
	else if (n == VERS)
		version_msg();

	exit(0);
}

/**
 * version_msg - This function displays a message containing version info
 */

void version_msg(void)
{
	char *time_n = get_time();

	printf("MKS - MaKe Script 1.0 (2023 December 24, compiled %s)\n", time_n);
	printf(
"Compiled with: gcc -Wall -pedantic -Werror -Wextra -std=gnu89 *.c -o mks\n\n");

	printf(
"      This program is a part of ALX Time Saver project\n"
"      It was created to help peers to create scripts fast and efficiently\n"
"\nWritten by Radouane Abounouas.\n");
}

/**
 * help_msg - This function displays a message containing help instruction
 */

void help_msg(void)
{
	printf("\nUsage:  mks [OPTION] FILE...\n");
	printf("        mks FILE...\n"
"\n"
"A FILE argument that does not exist is created with a shebang bash/python and execution right\n"
"if no option is given in the first run it will take bash shebang by default\n"
"\n"
"OPTION:\n"
"   This OPTION will be -b in the first run if run with no argument\n"
"\n"
"   -b           bash shebang             - '#!/bin/bash'\n"
"   -p           python shebang           - '#!/usr/bin/python3'\n"
"   -n           node shebang             - '#!/usr/bin/node'\n\n");
	printf(
"   -B           bash environ shebang     - '#!/usr/bin/env bash'\n"
"   -P           python environ shebang   - '#!/usr/bin/env python3'\n"
"   -N           node environ shebang     - #!/usr/bin/env node'\n"
"\n"
"		--help       display this help and exit\n"
"		--version     display the version information\n"
"\n"
"Note that if no OPTION is given it will take by default the OPTION used by the last execution of the command mks\n"
"\n");
	printf(
"After executing mks with '-p' OPTION once, you don't have to run the next with '-p' if you want the same script type\n"
"You only need to specify the OPTION if the current script is different than the previous one.\n"
"\n"
"EXAMPLE:\n"
"        mks -p test_py  ==> python script\n"
"        mks test_2      ==> python script\n"
"        mks -B test_sh  ==> bash script\n"
"        mks -b file_1 file_2 ... ==> create multiple file\n\n"
"        mks\n"
" $ Enter the name of the new script: FILE FILE...\n"
"\n");
}

/**
 * get_time - This function gets the current time
 *
 * Return: a string representation of the current time (compilation time)
 */

char *get_time(void)
{
	static char time_str[50];
	time_t current_time;
	struct tm *local_time;

	time(&current_time);

	local_time = localtime(&current_time);

	strftime(time_str, sizeof(time_str), "%b %d %Y %H:%M:%S", local_time);

	return (time_str);
}

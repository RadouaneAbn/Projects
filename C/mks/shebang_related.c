#include "header.h"

/**
 * add_shebang - This function adds a shebang in a existing script
 * @name: The name of the newlly created script
 * @type: The type of the shebang
 */

void add_shebang(const char *name, int type)
{
	FILE *f;
	const char *she_bang[4] = {"#!/bin/bash\n",
	"#!/usr/bin/python3\n",
	"#!/usr/bin/env bash\n",
	"#!/usr/bin/env python3\n"};

	f = fopen(name, "w");
	if (f == NULL)
	{
		fclose(f);
		err(OPEN, name);
	}

	fputs(she_bang[type], f);
	fclose(f);

}

/**
 * get_type - This function gets the type of the script
 *  if no flag is given upload it from /tmp/.mks_data
 *
 * Return: a flag '-b' for bash or '-p' for python
 */

char *get_type(void)
{
	struct stat fileSt;
	const char *data_file = "/tmp/.mks_data";
	char *type;
	FILE *f;

	/*<-- this variable will contain '-b' or '-p' -->*/
	type = malloc(sizeof(char) * 3);
	if (type == NULL)
	{
		perror("malloc: ");
		exit(1);
	}

	/*<-- Check if data file exists -->*/
	if (stat(data_file, &fileSt) != 0)
		create_data_file(data_file, NULL);

	/*<-- Open data file  -->*/
	f = fopen(data_file, "r");
	if (f == NULL)
		err(OPEN, data_file);

	/*<-- read the type from data file and store it in 'type' -->*/
	fseek(f, 6, SEEK_SET);
	if (fread(type, sizeof(char), 2, f) != 2)
	{
		fclose(f);
		free(type);
		err(READ, data_file);
	}
	type[2] = '\0';
	fclose(f);

	return (type);
}

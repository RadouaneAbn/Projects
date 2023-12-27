#include "header.h"

/**
 * make_script - This function makes the file
 *  add execution right then add shebang
 * @name: The name of the new script
 * @flag: The flag is the type of shebang bash/python
 */

void make_script(const char *name, const char *flag)
{
	int she_bang;

	/*<-- make the file + rwxr-xr-x rights -->*/
	built_file(name);
	if (!strcmp(flag, "-b"))
		she_bang = SH;
	else if (!strcmp(flag, "-p"))
		she_bang = PY;
	else if (!strcmp(flag, "-B"))
		she_bang = SE;
	else if (!strcmp(flag, "-P"))
		she_bang = PE;

	/*<-- add SheBang -->*/
	add_shebang(name, she_bang);
}

/**
 * built_file - This function will be called if the 'name' file doesn't exist
 *  it creates a new file and give it rwxr-xr-x rights
 * @name: The name of the file to be created
 */

void built_file(const char *name)
{
	FILE *f;

	/*<-- Create a file named 'name' -->*/
	f = fopen(name, "w");
	if (f == NULL)
		err(CREATE, name);

	fclose(f);

	/*<-- give if rwxr-xr-x rights -->*/
	chmod_file(name);
}

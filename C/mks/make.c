#include "header.h"

/**
 * main - Entry point
 * @ac: The number of arguments
 * @av: The arguments
 *
 * Return: alwase 0
 */

int main(int ac, char *av[])
{
	/*<-- start constructing teh script -->*/
	construct(ac, av);

	return (0);
}

/**
 * construct - This function initialize the construction of the script file
 * @ac: The number of arguments
 * @av: The arguments
 */

void construct(int ac, char *av[])
{
	struct stat fileSt;
	int i, nf = 0;
	char *type;

	/*<-- check for the help or version flag -->*/
	if (ac > 1 && !strcmp(av[1], "--help"))
		help(HELP);
	else if (ac > 1 && !strcmp(av[1], "--version"))
		help(VERS);
	/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/


	/*<-- Check if the command have no errors and returns -->*/
	/*<-- an index of the first file to be created -->*/
	i = CheckCmd(ac, av);

	/*<-- get the type of the script 'bash' or 'python' -->*/
	type = get_type();

	/*<-- Creates the script based on the type with execution right for all -->*/
	for (; i < ac; i++, nf++)
	{
		if (stat(av[i], &fileSt))
			make_script(av[i], type);
	}
	free(type);

	/*<-- if only one file is created, open it with VIM -->*/
	if (nf == 1)
		run_cmd("vim", av[i - 1]);
}

/**
 * CheckCmd - checks if the command have no errors
 * @ac: The number of arguments
 * @av: The arguments
 *
 * Return: an index of the first args after a flag if flag exists
 */

int CheckCmd(int ac, char *av[])
{
	int i = 1, idx;

	/*<-- Check for flag -->*/
	if (ac > 1 && (!strcmp(av[i], "-b") || !strcmp(av[i], "-p")
				|| !strcmp(av[i], "-B") || !strcmp(av[i], "-P")))
	{
		/*<-- if flag exists update the type of the script -->*/
		update_data_file(av[i]);
		i++;
	/*err(NOFILE, "mks");*/
	}

	if (i == ac)
		file_request();
	/*<-- The index of the first file if exists -->*/
	idx = i;

	/*<-- Check for aditional flags (if exist raise an error) -->*/
	for (; i < ac; i++)
	{
		if (av[i][0] == '-')
			err(OPTION, av[i]);
	}

	return (idx);
}

/**
 * file_request - This function requests a file name(s) in case no file
 *	name(s) is given
*/

void file_request(void)
{
	char *input = NULL, *file_name, *type, *first;
	struct stat fileSt;
	size_t size = 0;
	int nf = 0;

	printf("Enter the name of the new script: ");
	getline(&input, &size, stdin);

	type = get_type();

	file_name = strtok(input, " \n\t");
	while (file_name)
	{
		if (file_name[0] == '-')
			err(OPTION, file_name);
		else if (nf == 0)
			first = file_name;

		if (stat(file_name, &fileSt))
			make_script(file_name, type);

		file_name = strtok(NULL, " \n\t");
		nf++;
	}


	/*<-- if only one file is created, open it with VIM -->*/
	if (nf == 1)
		run_cmd("vim", first);
	free(type);
	free(input);
	exit(EXIT_SUCCESS);
}

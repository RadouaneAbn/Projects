#include "header.h"

/**
 * update_data_file - This function updates the flag stored in data file
 *  if given for future uses
 * @flag: The flag that deterimnes teh type of the script
 *
 */

void update_data_file(const char *flag)
{
	const char *data_file = "/tmp/.mks_data";
	FILE *f;
	struct stat fileSt;

	/*<-- Check if the data file exists-->*/
	if (stat(data_file, &fileSt) == 0)
	{
		f = fopen(data_file, "r+");
		/*<-- update the flag -->*/
		fseek(f, 6, SEEK_SET);
		fwrite(flag, sizeof(char), strlen(flag), f);
		fclose(f);
	}
	else
		/*<-- Create new one if it does not exist -->*/
		create_data_file(data_file, flag);
}

/**
 * create_data_file - This function creates data_file if it does not exist
 * @file_name: The name of the data file
 * @flag: The flag to be stored in it if it's given (-b by default)
 */

void create_data_file(const char *file_name, const char *flag)
{
	FILE *f;
	const char *default_type;

	/*<-- Check if flag is not NULL (exists) -->*/
	if (flag)
		default_type = flag;
	else
		default_type = "-b";

	/*<-- create a new file an write the type in it -->*/
	f = fopen(file_name, "w+");
	if (f == NULL)
		err(OPEN, file_name);
	fprintf(f, "type: %s", default_type);
	fclose(f);
}

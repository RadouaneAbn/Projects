#ifndef MAKE_H
#define MAKE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

#define SH 0
#define PY 1
#define SE 2
#define PE 3

#define USAGE 111
#define HELP 222
#define VERS 333
#define OPTION 444
#define READ 555
#define CHMOD 666
#define EXEC 777
#define OPEN 888
#define NOFILE 999
#define CREATE 897

#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define RST "\e[0m"

void construct(int ac, char *av[]);
int CheckCmd(int ac, char *av[]);
char *get_type(void);
void make_script(const char *name, const char *flag);

void built_file(const char *name);
void add_shebang(const char *name, int type);
void chmod_file(const char *name);
void run_cmd(const char *cmd, const char *name);
void create_data_file(const char *r, const char *flag);
void update_data_file(const char *flag);

/* help function */
void help(int n);
void help_msg(void);
void version_msg(void);
char *get_time(void);

/* error handling function */
void err(int n, const char *name);
void usage_msg(const char *name);
void option_msg(const char *name);
void read_msg(const char *name);
void chmod_msg(const char *name);
void exec_msg(const char *name);
void open_msg(const char *name);
void nofile_msg(const char *name);
void create_msg(const char *name);

/* if not file name(s) were given */
void file_request(void);

#endif

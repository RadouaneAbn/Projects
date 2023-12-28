#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 1024
#define DEC 10
#define HEX 16
#define OCT 8
#define BIN 2

/**
 * enum kind_e - Enumeration representing card suits.
 * @INT: integer
 * @LONG: long integer
 * @ULONG: unsigned long integer
 */

typedef enum kind_e
{
	INT,
	LONG,
	ULONG,
} type;

/**
 * struct opt_s - Structure representing options for formatting.
 *
 * @sign: The sign option (positive, negative).
 * @type: The type option (integer, string, character, etc.).
 * @flag: A flag associated with the option (d, i, b, etc.).
 * @op1: Additional option character.
 * @op2: Additional option character.
 */

typedef struct opt_s
{
	int sign;
	int type;
	char flag;
	char op1;
	char op2;
} opt_t;

/**
 * struct flag_s - Structure representing a formatting flag
 *	and its associated function.
 *
 * @csp: The format specifier character (c, s, d, etc.).
 * @f: A function pointer to the corresponding formatting function.
 */

typedef struct flag_s
{
	char csp;
	int (*f)(char *buffer, va_list args, int idx, char F);
} flag_t;

int _printf(const char *format, ...);
int char_f(char *buffer, va_list args, int idx, char F);
int string_f(char *buffer, va_list args, int idx, char F);
int string_s(char *buffer, va_list args, int idx, char F);
int number_f(char *buffer, va_list args, int idx, char F);
int number_u(char *buffer, va_list args, int idx, char F);
char *inToStr(unsigned long n, int type, int sign);
int check_elegible(const char *format, int i);
int address(char *buffer, va_list args, int idx, char F);
int strcnt(char *buffer, int idx, char *src);

#endif /* MAIN_H */

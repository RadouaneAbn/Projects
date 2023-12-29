#ifndef DATA_H
#define DATA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define BUF_SIZE 1024
#define NUMBER 123
#define STRING 456

typedef enum kind_e
{
	INT,
	CHR,
	STR,
	FLOAT,
} kind;

typedef struct Block
{
    kind type;
    void *data;
} Block_t;

void getInput(Block_t *node);
char *elegible(Block_t *node);

#endif /* DATA_H */
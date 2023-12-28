#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

#include <stdio.h>
#include <stdlib.h>

typedef enum kind_e
{
	INT,
	LONG,
	ULONG,
	CHR,
	STR,
	FLOAT,
} kind;

typedef struct Node_s
{
	void *data;
	int type;
	struct Node_s *next;
} Node_t;

typedef struct list_s
{
	struct Node_t *head;
	int size;
	void *p;
} list_t;



Node_t *add_node(Node_t **head, void *p, int type);
size_t print_list(Node_t *head);
size_t print_list_type(Node_t *head);
void free_list(Node_t *head);

#endif /* LINKEDLISTS_H */

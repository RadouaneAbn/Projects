#include "LinkedLists.h"

/**
 * add_nodeint - this function adds a new node at the beginning
 *	of a listint_t list
 * @head: pointer to pointer to head of linked list
 * @n: a number
 *
 * Return: the address of the new elements
 *	NULL in case of failure
 */

Node_t *add_node(Node_t **head, void *p, int type)
{
	Node_t *new = malloc(sizeof(Node_t));

	if (new == NULL)
		return (NULL);

	new->data = p;
	new->type = type;
	new->next = *head;

	*head = new;

	return (new);
}

/**
 * print_list - This function prints a linked list
 * @head: The head of teh linked list
 *
 * Return: The number of nodes printed
 */

size_t print_list(Node_t *head)
{
	size_t count = 0;
	Node_t *current = head;
	int type;

	while (current)
	{
		type = current->type;
		if (type == INT)
			printf("%d\n", *(int *)current->data);
		else if (type == STR)
			printf("%s\n", (char *)current->data);
		else if (type == CHR)
			printf("%c\n", *(char *)current->data);
		else if (type == LONG)
			printf("%ld\n", *(long *)current->data);
		else if (type == ULONG)
			printf("%lu\n", *(unsigned long *)current->data);
		else if (type == FLOAT)
			printf("%f\n", *(float *)current->data);
		current = current->next;
		count++;
	}

	return (count);
}

/**
 * free_list - This function frees a linked list
 * @head: The head of the linked list
 */

void free_list(Node_t *head)
{
	Node_t *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * print_list_type - This function prints a linked list along with
 *  the type of each node
 * @head: The head of teh linked list
 *
 * Return: The number of nodes printed
 */

size_t print_list_type(Node_t *head)
{
	size_t count = 0;
	Node_t *current = head;
	int type;

	while (current)
	{
		type = current->type;
		if (type == INT)
			printf("%d (int)\n", *(int *)current->data);
		else if (type == STR)
			printf("%s (str)\n", (char *)current->data);
		else if (type == CHR)
			printf("%c (char)\n", *(char *)current->data);
		else if (type == LONG)
			printf("%ld (long)\n", *(long *)current->data);
		else if (type == ULONG)
			printf("%lu (unsigned long int)\n", *(unsigned long *)current->data);
		else if (type == FLOAT)
			printf("%f (float)\n", *(float *)current->data);
		current = current->next;
		count++;
	}

	return (count);
}

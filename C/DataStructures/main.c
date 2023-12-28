#include "LinkedLists.h"

/**
 * main - The entry point
 *
 * Return: always 0
 */

int main(void)
{
	Node_t *head;
	int n, m, size, i;

	head = NULL;
	int a = 2147483647, b = -984;
	long int c = -2147483647;
	unsigned long int u = 4294967295;
	char d = 'd', *s = "Hello world";


	add_node(&head, &a, INT);
	add_node(&head, &b, INT);
	add_node(&head, &c, LONG);
	add_node(&head, &u, ULONG);
	add_node(&head, &d, CHR);
	add_node(&head, s, STR);

	printf("----------------\n\n");
	n = print_list(head);
	printf("\n################\n################\n\n");
	print_list_type(head);
	printf("\n----------------\n");

	free_list(head);
	for (m = n, size = 0; m; m /= 10)
		size++;

	printf("\nThe number of nodes printed:----[%d]\n", n);
	printf("                                 ");
	for (i = 0; i < size; i++)
		printf("^");
	printf("\n\n");

	return (0);
}

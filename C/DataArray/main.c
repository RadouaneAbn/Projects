#include "Data.h"

void clearInputBuffer() {
	char c;
	while ((c = fgetc(stdin)) != '\n' && c != EOF);
}

int main(void)
{
	char *buf;
	size_t size, i;
	Block_t *array;
	kind type;

	printf("The size of the array: ");
	scanf("%lu", &size);

	// printf("size: %lu\n\n", size); /*debug*/
	clearInputBuffer();



	array = (Block_t *)malloc(sizeof(Block_t) * size);


	for (i = 0; i < size; i++)
	{
		// printf("start [%ld]\n\n", i); /*debug*/
		getInput(&array[i]);
		// printf("\nend\n"); /*debug*/

	}


	return (0);
}

void getInput(Block_t *node)
{
	char *buf;
	// printf("getInput "); /*debug*/
	char *tt[3] = {"<int>", "<char>", "<str>"};

	while ((buf = elegible(node)) == NULL);


	printf("[%s] [%s]\n", buf, tt[node->type]);

	// node = getType(buf);
}

char *elegible(Block_t *node)
{
	char buf[1024], *result;
	int i = 0, size;
	// printf("here1"); /*debug*/

	printf(">>-> ");
	fgets(buf, 1024, stdin);
	// clearInputBuffer(); use this when using scanf
	// scanf("%[^\n]", buf); This is trouble, WHY ???

	char *last = strrchr(buf, '\n');
	if (last)
		*last = '\0';

	size = strlen(buf);
	if(!buf[0])
		return (NULL);

	if (buf[i] == '\"'){
		if (buf[size - 1] == '\"'){
			result = malloc(size - 1);
			strncpy(result, buf + 1, size - 1);
			result[size - 2] = '\0';
			node->type = STR;
			return (result);
		}
		else{
			printf("Forgot to close double quots \"\" at the end\n");
			return (NULL);
		}
	}
	else if (buf[i] == '\''){
		if (buf[size - 1] == '\''){
			if (size > 3){
				printf("Use double Quots for \"string...\"\n");
				return (NULL);
			}
			result = malloc(1);
			strncpy(result, buf + 1, 1);
			node->type = CHR;
			return (result);
		}
		else{
			printf("Forgot to close quots \'\' at the end\n");
			return (NULL);
		}
	}
	else{
		if (buf[i] == '-')
			i++;

		for (; i < size; i++){
			if (buf[i] < 48 || buf[i] > 57){
				printf("you forgot double quots \"string...\"\n");
				return (NULL);
			}
		}
		result = malloc(size - 1);
		strcpy(result, buf);
		node->type = INT;
		return (result);
	}
}


// Block_t *getType(char *str)
// {
//     int i = 0;
//     kind type = NUMBER;



//     while (str[i])
//     {
//         if (str[i] < 48 && str[i] > 57)
//             return (STRING);
//         else if (str[i] == '.')
//         i++;
//     }

//     return (NUMBER);
// }

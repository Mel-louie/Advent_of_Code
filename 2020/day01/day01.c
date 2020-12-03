/* + - + - + - +  - + - + - + - + - + - + */
/*  Find the two entries that sum to 2020 */
/* + - + - + - +  - + - + - + - + - + - + */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct  node
{
    int         value;
    struct node *next;
}               node;

typedef struct	tab
{
	int			**stock;
	int			count;
}				tab;

void	create_list(FILE *file, node **head_base)
{
	node	*current_node;
	node	*head = *head_base;
	node	*tail;

	while (!feof(file))
	{
		current_node = malloc(sizeof(struct node));
		fscanf(file, "%d\n", &current_node->value);
		current_node->next = NULL;

		if (NULL == head)
		{
			head = current_node;
			tail = current_node;
		}
		else
		{
			tail->next = current_node;
			tail = current_node;
		}
	}
	//Store back the updated head pointer
	*head_base = head;
}

/*
void  print_list(node **head_base)
{
    node    *tmp_node = *head_base;

    while(tmp_node->next != NULL)
    {
        printf("%d\n", tmp_node->value);
        tmp_node = tmp_node->next;
    }
    printf("%d\n", tmp_node->value);
}*/

void	stock_list(node **head_base, tab *t)
{
	node    *tmp_node = *head_base;
	int		i = 0;
	node	*tmp2_node = *head_base;

	t->count = 0;
    while(tmp_node->next != NULL)
    {
        tmp_node = tmp_node->next;
		t->count++;
    }
	t->count += 1;
	t->stock = malloc(sizeof(char) * t->count);
	while (i < t->count)
	{
		t->stock[i] = &tmp2_node->value;
		tmp2_node = tmp2_node->next;
		i++;
	}
}

void delete_list(node **head_base)
{
    node    *head = *head_base;
    node    *tmp;

    while(NULL != head)
    {
        tmp = head; // Get a temp pointer
        head = head->next; // Move head pointer
        tmp->next = NULL; // break the link
        free(tmp);
    }
    // Store the head pointer back which should be NULL
    *head_base = head;
}

int	calc_input(tab *t)
{
	int i = 0;
	int j = t->count - 1;

	while (t->stock[i])
	{
		while (j > i)
		{
			if (((*t->stock[i]) + (*t->stock[j])) == 2020)
				return ((*t->stock[i]) * (*t->stock[j]));
			j--;
		}
		j = t->count - 1;
		i++;
	}
	return (0);
}

/*
** Step by step:
** - Open the file input;
** - Parse the file and create a list, line by line (create_list());
** - Stock this list in a array (stock_list());
** - Calculate int of the array to find two wich sum is equal to 2020;
** - Delete the list and free the array, close the file.
*/

int     main(void)
{
    FILE    *file;
    node    *head = NULL;
	int		sum = 2020;
	tab		t;	

	t.stock = NULL;
    if (!(file = fopen("input", "r")))
    {
		printf("impossible d'ouvrir le fichier\n");
		return (-1);
	}
	create_list(file, &head);
//	print_list(&head);
	stock_list(&head, &t);
	if (calc_input(&t))
		printf("result %d\n", calc_input(&t));
	delete_list(&head);
	free(t.stock);
	t.stock = NULL;
    fclose(file);
//	system("leaks a.out");
    return (0);
}
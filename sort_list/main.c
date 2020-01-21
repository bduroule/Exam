#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int		ascending(int a, int b)
{
	return (a < b);
}

void ft_print(t_list *h)
{
	while (h)
	{
		printf("%d, ", h->data);
		h = h->next;
	}
	printf("\n");
}

int main (void)
{
	t_list *n1 = (t_list *)malloc(sizeof(t_list));
	t_list *n2 = (t_list *)malloc(sizeof(t_list));
	t_list *n3 = (t_list *)malloc(sizeof(t_list));
	t_list *n4 = (t_list *)malloc(sizeof(t_list));
	t_list *n5 = (t_list *)malloc(sizeof(t_list));
	t_list *n6 = (t_list *)malloc(sizeof(t_list));
	t_list *n7 = (t_list *)malloc(sizeof(t_list));

	n1->data = 5;
	n2->data = 2147483647;
	n3->data = 357;
	n4->data = -50;
	n5->data = 20;
	n6->data = -214748648;
	n7->data = 2;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = NULL;

	int (*cmp)(int, int) = &ascending;
	sort_list(n1, cmp);
	ft_print(n1);
	return 0;
}
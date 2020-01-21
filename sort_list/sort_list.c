#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *tmp;
	int i;

	tmp = lst;
	while (lst->next)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			i = lst->data;
			lst->data = lst->next->data;
			lst->next->data = i;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return lst;
}
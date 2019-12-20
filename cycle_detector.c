/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cycle_detector.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/13 15:17:00 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/13 15:17:06 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


typedef struct     s_list 
{
    int            data;
    struct s_list  *next;
}                  t_list;


int        cycle_detector(const t_list *list)
{
    const t_list *slow = list;
    const t_list *fast = list;

    if (!list)
        return 0;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
            return 1;
    }
    return 0;
}



/*
** MAIN
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	t_list *node1 = malloc(sizeof(t_list));;
	t_list *node2 = malloc(sizeof(t_list));;
	t_list *node3 = malloc(sizeof(t_list));;
	t_list *node4 = malloc(sizeof(t_list));;

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;
	printf("%d\n", cycle_detector(node1));
    return 0;
}

/*
** MAIN
*/

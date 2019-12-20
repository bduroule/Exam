/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sort_int_tab.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 18:34:38 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 18:34:39 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>

void ft_swap(int *tab, unsigned int a, unsigned int b)
{
    int tmp;
    
    tmp = tab[a];
    tab[a] = tab[b];
    tab[b] = tmp;
}

void sort_int_tab(int *tab, unsigned int size)
{
    unsigned int i = -1;
    unsigned int j = -1;

    if (size <= 1)
        return ;
    while (++i < size)
    {
        j = -1;
        while (++j < size - 1)
            if (tab[j] > tab[j + 1])
                ft_swap(tab, j, j + 1);
    }
}

/*
** MAIN
*/

int main(int ac, char **av)
{
    int tab[10] = {150, 25, -10, 2147483647, 1, 300, -2147483648, 8, 5, -8};
    int i = -1;
    
    sort_int_tab(tab, 10);
    while (++i < 10)
        printf("%d, ", tab[i]);
    return 0;
}

/*  
** Assignment name  : sort_int_tab
** Expected files   : sort_int_tab.c
** Allowed functions: 
** --------------------------------------------------------------------------------
** 
** Écrire la fonction suivante:
** 
** void sort_int_tab(int *tab, unsigned int size);
** 
** Cette fonction doit trier (en place !) le tableau d'ints 'tab', qui contient
** exactement 'size' entrées, dans l'ordre croissant.
** 
** Les doublons doivent être préservés.
** 
** Les entrées seront toujours cohérentes.
*/

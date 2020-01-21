/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 11:59:13 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 11:59:17 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h> 

char    *ft_itoa_base(int value, int base)
{
    int si;
    int i = 0;
    char *str;
    int n;

    n = (value < 0) ? -(long)value : value;
    si = (value < 0 && base == 10) ? -1 : 0;
    i = (si == -1) ? 2 : 1;
    while (n /= base)
        i++;
    str = (char *)malloc(sizeof(char) * i + 1);
    str[i] = '\0';
    n = value < 0 ? -(long)value : value;
    while (i-- + si)
    {
        str[i] = n % base + (n % base < 10 ? '0' : 'A' - 10);
        n /= base;
    }
    (i == 0) ? str[i] = '-' : 0;
    return str;                                                                                                     
}   


/*
** MAIN
*/

int main(int ac, char **av)
{
    char *str;

    str = ft_itoa_base(atoi(av[1]), atoi(av[2]));
    printf("%s\n", str);
    return 0;
}

/*
** MAIN
*/

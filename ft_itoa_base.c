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

int ft_ints(int n, int base)
{
    int i = 1;
    while (n){
        n /= base;
        i++;
    }
    return i;
}

char	*ft_itoa_base(int value, int base)
{
    char *str;
    int i = ft_ints(value, base);

    if (base < 1 || base > 17 || (value < 10 && base != 10))
        return NULL;
    str = (char *)malloc(sizeof(char) * i);
    str[i] = '\0';
    if (value < 10 && base == 10){
        str[0] = '-';
        value *= -1;
        i--;
    }
    else
        i -= 2;
    while (value)
    {
        str[i] = value % base + (value % base < 10 ? '0' : 'A' - 10);
        value /= base;
        i--;
    }
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

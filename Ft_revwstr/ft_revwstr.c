/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_revwstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/16 17:58:58 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/16 17:59:00 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int is_spa(char c)
{
    return (c == ' ' || c == '\n');
}

void    rev_wstr(char *str)
{
    int i = 0;
    int start;
    int end;

    while (str[i])
        i++;
    while (i > 0)
    {
        while (str[i] && is_spa(str[i]))
            i--;
        end = i;
        while (str[i] && !is_spa(str[i]))
            i--;
        i++;
        start = i;
        while (start <= end)
            write(1, &str[start++], 1);
        if (str[i - 1])
            write(1,  " ", 1);
        i -= 2;
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
        rev_wstr(av[1]);
    write(1, "\n", 1);
    return 0;
}

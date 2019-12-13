/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bracket.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 11:59:41 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 11:59:43 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h> 
#include <stdio.h>

int check_b(char a, char b)
{
    return ((a == '{' && b == '}') || (a == '(' && b == ')') || (a == '[' && b == ']'));
}

int barcket(char *str)
{
    int i = -1;
    char tmp[4168] = {0};
    int j = 0;

    while (str[++i])
    {
        if (str[i] == '[' || str[i] == '{' || str[i] == '(')
            tmp[++j] = str[i];
        if (str[i] == ']' || str[i] == '}' || str[i] == ')')
            if (!(check_b(tmp[j--], str[i])))
                return (0);
    }
    return !j;
}

int main(int ac, char **av)
{
    int i = 0;
    if (ac == 1)
        return(write(1, "\n", 1));
    while (++i < ac)
    {
        if (barcket(av[i]))
            write(1, "OK\n", 3); 
        else
            write(1, "Error\n", 6);
    }
    return(0);
}

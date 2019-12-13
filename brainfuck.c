/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   brainfuck.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 13:03:23 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 13:03:28 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

int w_brain(char *str, int i)
{
    int loop = 0;

    if (str[i] == '[')
    {
        i++;
        while (!(str[i] == ']' && loop == 0))
        {
            if (str[i] == '[' || str[i] == ']')
                str[i] == '[' ? loop++ : loop--;
            i++;
        }
        i--;
    }
    else if (str[i] == ']')
    {
        i--;
        while (!(str[i] == '[' && loop == 0))
        {
            if (str[i] == ']' || str[i] == '[')
                str[i] == ']' ? loop++ : loop--;
            i--;
        }
        i--;
    }
    return (i);
}

int brain_fuck(char *str)
{
    char ptr[4096] = {0};
    int i = -1;
    int j = 0;

    while (str[++i])
    {
        if (str[i] == '>' || str[i] == '<')
            str[i] == '>' ? j++ : j--;
        else if (str[i] == '+' || str[i] == '-')
            str[i] == '+' ? ptr[j]++ : ptr[j]--;
        else if (str[i] == '.')
            write(1, &ptr[j], 1);
        else if (str[i] == '[' && ptr[j] == 0)
                i = w_brain(str, i);
        else if (str[i] == ']' && ptr[j])
                i = w_brain(str, i);
    }
    return 0;
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (write(1, "\n", 1));
    brain_fuck(av[1]);
}
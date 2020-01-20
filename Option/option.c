/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   option.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/13 15:17:18 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/13 15:17:19 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

int is_aplpha(char a)
{
    return (a >= 'a' && a <= 'z');
}

int main(int ac, char **av)
{
    int tab[32] = {0};
    int i = 0;
    int j;

    if (ac < 2)
        return (write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36));
    while (++i < ac)
    {
        j = 0;
        while (av[i][++j])
        {
            if (av[i][0] == '-')
            {
                if (av[i][j] == 'h')
                    return (write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36));
                else if (!(is_aplpha(av[i][j])))
                    return(write(1, "Invalid Option\n", 15));
                else
                    tab['z' - av[i][j] + 6] = 1;
            }
            else
                return(write(1, "Invalid Option\n", 15));
        }
    }
    i = 0;
    while (i < 32)
    {
        tab[i] = '0' + tab[i];
        write(1, &tab[i++], 1);
        if (i % 8 == 0)
            write(1, " ", 1);
    } 
	write(1, "\n", 1);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   biggest_pal.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/13 15:16:51 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/13 15:16:52 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
** OK
*/

#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int start = 0;
    int size = 0;

    if (ac != 2)
        return (write(1, "\n", 1));
    while (av[1][i])
    {
        k = 1;
        j = 1;
        while (av[1][i + k] == av[1][i])
            k++;
        if (size <= k){
            size = k;
            start = i;
        }
        while (av[1][i - j] == av[1][i + j + k - 1])
        {
            if ((2 * j + k) >= size && i - j > 0){
                size = 2 * j + k;
                start = i - j;
            }
            j++;
        }
        i++;
    }
    write(1, av[1] + start, size);
    write(1, "\n", 1);
}

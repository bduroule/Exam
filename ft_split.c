/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 19:24:19 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 19:24:21 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include <stdlib.h>
# include <stdio.h>

int ft_spa(char a)
{
    return (a == ' ' || a == '\t' || a == '\n');
}

/*int count_word(char *str)
{
    int i = 0;
    int size = 0;

    while (str[i])
    {
        while (str[i] && ft_spa(str[i]))
            i++;
        if (!ft_spa(str[i] && str[i])){
            printf("%c}\n", str[i]); size++;
            while (str[i] && !ft_spa(str[i]))
                i++;
        }
    }
    return size;
}*/


/*char    **ft_split(char *str)
{
    char **tab;
    int i = 0;

    tab = (char **)malloc(sizeof(char *) * 1000000);
    while (str[i])
    {
        while (ft_spa(str[i]))
            i++;
    }
}*/

int main(int ac, char **av)
{
    printf("%d\n" ,count_word(av[1]));
    return 0;
}

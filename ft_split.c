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

int count_word(char *str)
{
    int i = 0;
    int size = 0;

    while (str[i])
    {
        while (str[i] && ft_spa(str[i]))
            i++;
        if (!ft_spa(str[i] && str[i])){
            size++;
            while (str[i] && !ft_spa(str[i]))
                i++;
        }
    }
    return size;
}

char *mall_word(char *str)
{
    int i = 0;
    char *word;

    while (str[i] && ft_spa(str[i]))
        i++;
    word = (char *)malloc(sizeof(char) * i + 1);
    i = 0;
    while (str[i] && !ft_spa(str[i]))
    {
        word[i] = str[i];
        i++;
    }
    word[i] = '\0';
    return (word);
}


char    **ft_split(char *str)
{
    char **tab;
    int i = 0;

    tab = (char **)malloc(sizeof(char *) * count_word(str) + 1);
    while (*str)
    {
        while (*str && ft_spa(*str))
            str++;
        if (!ft_spa(*str))
        {
            tab[i++] = mall_word(str);
            while (*str && !ft_spa(*str))
              str++;
        }
    }
    tab[i] = NULL;
    return tab;
}

int main(int ac, char **av)
{
    char **tab = ft_split(av[1]);

    for (int i = 0; tab[i]; i++)
        printf("{%s}\n", tab[i]);
    return 0;
}

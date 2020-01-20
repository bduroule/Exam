/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rostring.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 17:53:39 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 17:53:40 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

int is_spa(char c)
{
    return (c == ' ' || c == '\t');
}

void rostring(char *str)
{
    int i = 0;
    int start = 0;
    int size = 0;
    int spa = 0;

    while (str[i] && is_spa(str[i]))
        i++;
    start = i;
    while (str[i] && !is_spa(str[i])){
        size++;
        i++;
    }
    while (str[i])
    {
        while (str[i] && is_spa(str[i]))
            i++;
        if (spa)
            write(1, " ", 1);
        while(str[i] && !is_spa(str[i]))
            write(1, str + i++, 1);
        spa++;
    }
    write(1, " ", 1);
    write(1, str + start, size);
    write(1, "\n", 1);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (write(1, "\n", 1));
    rostring(av[1]);
}


/*
**  Assignment name  : rostring
**  Expected files   : rostring.c
**  Allowed functions: write, malloc, free
**  --------------------------------------------------------------------------------
**  
**  Écrire un programme qui prend en paramètre une chaîne de caractères, et qui
**  affiche cette chaîne en procédant à une rotation d'un mot de droite à gauche.
**  
**  Ainsi, le premier mot se retrouver le dernier et les autres restent dans l'ordre.
**  
**  On appelle "mot" une portion de chaîne de caractères délimitée soit par des
**  espaces et/ou des tabulations, soit par le début / fin de la chaîne.
**  
**  Les mots seront affichés séparés par un seul et unique espace.
**  
**  Si le nombre de paramètres est inférieur à 1, le programme devra afficher '\n'.
**  
**  Exemple:
**  
**  $>./rostring "abc   " | cat -e
**  abc$
**  $>
**  $>./rostring "Que la      lumiere soit et la lumiere fut"
**  la lumiere soit et la lumiere fut Que
**  $>
**  $>./rostring "     AkjhZ zLKIJz , 23y"
**  zLKIJz , 23y AkjhZ
**  $>
**  $>./rostring | cat -e
**  $
**  $>
*/


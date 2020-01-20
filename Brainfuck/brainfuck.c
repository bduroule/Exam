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

int w_brain(char *str, int j, int way)
{
	int	i = 0;
    
	while (1)
	{
		if (str[j] == '[' || str[j] == ']')
			str[j] == ']' ?  i++ : i--;
		if (i == 0)
			return (j);
		j += way;
	}
	return (0);
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
                i = w_brain(str, i, 1);
        else if (str[i] == ']' && ptr[j])
                i = w_brain(str, i, -1);
    }
    return 0;
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (write(1, "\n", 1));
    brain_fuck(av[1]);
}

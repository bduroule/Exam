/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_memory.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 11:59:34 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 11:59:36 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void	print_memory(const void *addr, size_t size)
{
    unsigned const char *ptr = addr;
	char base[16] = "0123456789abcdef";
	int i = 0;
	int j = -1;
	char tab[17];

	tab[16] = '\0';
	while (i < size || i % 16)
	{
		if (i < size){
			write(1, base + ptr[i] / 16, 1);
			write(1, base + ptr[i] % 16, 1);
			tab[i % 16] =  (ptr[i] >= 32 && ptr[i] <= 126) ? ptr[i] : '.';
		}
		else
			write(1, "  ", 2);
		if (++i % 2 == 0)
			write(1, " ", 1);
		if (i % 16 == 0)
		{
			j = -1;
			while (tab[++j])
			{
				write(1, tab + j, 1);
				tab[j] = '\0';
			}
			write(1, "\n", 1);
		}
	}
}

int main(int ac, char **av)
{
    int	tab[10] = {0, 23, 150, 255,
	12, 16,  21, 42};

	print_memory(tab, sizeof(tab));
	return (0);
}

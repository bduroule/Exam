/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_momory.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 11:59:34 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 11:59:36 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>


void	print_memory(const void *addr, size_t size);
{
    unsigned char *ptr = (unsigned char)addr;
	char base[16] = "0123456789abcdef";
	int i = 0;

	while (i < size)
	{
		write(1, base + ptr[i] / 16, 1);
		write(1, base + ptr[i] % 16, 1);
	}
}


int main(int ac, char **av)
{
    int	tab[10] = {0, 23, 150, 255,
	12, 16,  21, 42};

	print_memory(tab, sizeof(tab));
	return (0);
}

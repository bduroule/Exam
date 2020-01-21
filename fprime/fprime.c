#include <stdio.h>
#include <stdlib.h>

void	fprime(int nb)
{
	int div = 2;

	if (nb < 1)
		return ;
	if (nb == 1)
		printf("1");
	while (div <= nb)
	{
		if (nb % div == 0)
		{
			printf("%d", div);
			if (div == nb)
				return ;
			printf("*");
			nb /= div;
			div = 1;
		}
		div++;
	}

}

int main(int ac, char **av)
{
	if (ac == 2)
		fprime(atoi(av[1]));
	printf("\n");
	return 0;
}
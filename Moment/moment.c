/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   moment.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: exam <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/14 11:01:37 by exam         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 12:03:43 by exam        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
** OK
*/

#include <stdlib.h>
#include <unistd.h>

unsigned int	i_s(unsigned int n)
{
	int i = 1;

	if (n == 0)
		return (i + 1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return i;
}

char	*ft_itoa(unsigned int n)
{
	char *str;
	unsigned int i = i_s(n);
	
	str = (char *)malloc(sizeof(char) * i + 1);
	i--;
	str[i] = '\0';
	i--;
	if (n == 0)
		return ("0");
	while (n)
	{
		str[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	return str;
}

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return i;
}

char *ft_cat(char *s1, char *s2)
{
	char *str;
	int i = -1;
	int j = 0;

	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char    *moment(unsigned int duration)
{
	char *str;

	if (duration == 1)
		str = ft_cat("1", " second ago.");
	else if (duration < 60)
		str = ft_cat(ft_itoa(duration), " seconds ago.");
	else if (duration < 120)
		str = ft_cat("1", " minute ago.");
	else if (duration < 3600)
		str = ft_cat(ft_itoa(duration / 60), " minutes ago.");
	else if (duration < 7200)
		str = ft_cat("1", " hour ago.");
	else if (duration < 86400)
		str = ft_cat(ft_itoa(duration / 3600) , " hours ago.");
	else if (duration < 172800)
		str = ft_cat("1", " day ago.");
	else if (duration < 2592000)
		str = ft_cat(ft_itoa(duration / 86400) , " days ago.");
	else if (duration < 5184000)
		str = ft_cat("1" , " month ago.");
	else
		str = ft_cat(ft_itoa(duration / 2592000) , " months ago.");
	return (str);
}


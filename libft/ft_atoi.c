/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitavare <mitavare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 11:24:39 by mitavare          #+#    #+#             */
/*   Updated: 2026/10/22 08:00:18 by mitavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	value;
	int	signal;

	i = 0;
	value = 0;
	signal = 1;
	while (str[i] == ' ' || (9 <= str[i] && 13 >= str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signal *= -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		value *= 10;
		value += (str[i] - 48);
		i++;
	}
	return (signal * value);
}

/*
#include <stdio.h>
int	main(void)
{
	char	*nb1 = "	23";
	char	*nb2 = "-43a4";
	char	*nb3 = "0";
	char	*nb4 = "-2147483648";
	char	*nb5 = "2147483647";
	printf("%d", ft_atoi(nb1));
	printf("\n");
	printf("%d", ft_atoi(nb2));
	printf("\n");
	printf("%d", ft_atoi(nb3));
	printf("\n");
	printf("%d", ft_atoi(nb4));
	printf("\n");
	printf("%d", ft_atoi(nb5));
}
*/

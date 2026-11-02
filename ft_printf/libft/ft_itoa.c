/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitavare <mitavare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 12:25:12 by mitavare          #+#    #+#             */
/*   Updated: 2026/10/27 12:32:01 by mitavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	number_length(long n)
{
	size_t	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	fill_number(long n, char *str, size_t *i)
{
	if (n >= 10)
		fill_number(n / 10, str, i);
	str[(*i)++] = (n % 10) + '0';
}

char	*ft_itoa(int n)
{
	char	*str;
	long	number;
	size_t	i;

	number = n;
	str = malloc(number_length(number) + 1);
	if (!str)
		return (NULL);
	i = 0;
	if (number < 0)
	{
		str[i++] = '-';
		number = -number;
	}
	fill_number(number, str, &i);
	str[i] = '\0';
	return (str);
}

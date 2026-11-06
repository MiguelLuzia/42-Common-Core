/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cdus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitavare <mitavare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:03:41 by mitavare          #+#    #+#             */
/*   Updated: 2026/11/06 12:12:11 by mitavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fill_c(int arg)
{
	ft_putchar_fd(arg, 1);
	return (1);
}

int	fill_d(int arg)
{
	int	count;

	count = 0;
	if (arg == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else
	{
		if (arg < 0)
		{
			ft_putchar_fd('-', 1);
			count++;
			arg *= -1;
		}
		if (arg >= 10)
			count += fill_d(arg / 10);
		ft_putchar_fd((arg % 10) + '0', 1);
	}
	return (count + 1);
}

int	fill_u(unsigned int arg)
{
	int	count;

	count = 0;
	if (arg >= 10)
		count += fill_u(arg / 10);
	ft_putchar_fd((arg % 10) + '0', 1);
	return (count + 1);
}

int	fill_s(char *arg)
{
	if (!arg)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(arg, 1);
	return (ft_strlen(arg));
}

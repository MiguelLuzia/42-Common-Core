/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_hexp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitavare <mitavare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:05:52 by mitavare          #+#    #+#             */
/*   Updated: 2026/11/06 12:07:16 by mitavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fill_hex(unsigned long arg, int upper)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	if (upper)
		base = "0123456789ABCDEF";
	count = 0;
	if (arg >= 16)
		count += fill_hex(arg / 16, upper);
	ft_putchar_fd(base[arg % 16], 1);
	return (count + 1);
}

int	fill_p(void *arg)
{
	if (!arg)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	return (2 + fill_hex((unsigned long)arg, 0));
}

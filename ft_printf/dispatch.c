/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitavare <mitavare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:00:21 by mitavare          #+#    #+#             */
/*   Updated: 2026/11/06 12:00:48 by mitavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dispatch(char c, va_list *ap)
{
	if (c == 'c')
		return (fill_c(va_arg(*ap, int)));
	if (c == 'd' || c == 'i')
		return (fill_d(va_arg(*ap, int)));
	if (c == 'u')
		return (fill_u(va_arg(*ap, unsigned int)));
	if (c == 's')
		return (fill_s(va_arg(*ap, char *)));
	if (c == 'p')
		return (fill_p(va_arg(*ap, void *)));
	if (c == 'x')
		return (fill_hex(va_arg(*ap, unsigned int), 0));
	if (c == 'X')
		return (fill_hex(va_arg(*ap, unsigned int), 1));
	return (fill_c(c));
}

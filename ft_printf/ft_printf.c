/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitavare <mitavare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:15:00 by mitavare          #+#    #+#             */
/*   Updated: 2026/11/02 11:57:18 by mitavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_args(const char *s)
{
	int i = 0;
	int nargs = 0;

	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] != '%')
			nargs++;
		else if (s[i] == '%' && s[i + 1] == '%')
			i++;
		i++;
	}
	return (nargs);
}

void fill_char_int(const char *s, int *i, int arg)
{
	if (s[(*i) + 1] == 'c')
		ft_putchar_fd(arg, 1);
	else if (s[(*i) + 1] == 'd')
		ft_putnbr_fd(arg , 1);
	(*i)++;
}

// void fill_unsigned_int(const char *s, int *i, unsigned int arg)
// {
// 	if (s[(*i) + 1] == 'c')
// 		ft_putchar_fd(arg, 1);
// 	else if (s[(*i) + 1] == 'd')
// 		ft_putnbr_fd(arg , 1);
// 	(*i)++;
// }

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		nargs;
	int		c;
	int		i;

	nargs = count_args(s);
	c = 0;
	i = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%' && (s[i + 1] == 'c' || s[i + 1] == 'd'))
			fill_char_int(s, &i, va_arg(ap, int));
		else if (s[i] == '%' && s[i + 1] == '%')
		{
			ft_putchar_fd('%', 1);
			i++;
		}
		else
			ft_putchar_fd(s[i], 1);
		i++;
	}
	va_end(ap);
	return (c);
}

#include <stdio.h>
int main(void)
{
	int i = ft_printf("Hello %% %c%c%d.", 'a', 'b', 1000);
	printf("\n%d", i);
}

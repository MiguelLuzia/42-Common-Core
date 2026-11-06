/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitavare <mitavare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:28:03 by mitavare          #+#    #+#             */
/*   Updated: 2026/11/06 12:07:39 by mitavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *s, ...);
int	ft_dispatch(char c, va_list *ap);
int	fill_c(int arg);
int	fill_d(int arg);
int	fill_u(unsigned int arg);
int	fill_s(char *arg);
int	fill_hex(unsigned long arg, int upper);
int	fill_p(void *arg);

#endif

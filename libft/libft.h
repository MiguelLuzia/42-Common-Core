/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitavare <mitavare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 11:14:21 by mitavare          #+#    #+#             */
/*   Updated: 2026/10/21 12:25:43 by mitavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

int				ft_isalpha(char *str);
int				ft_isdigit(char *str);
int				ft_isalnum(char *str);
int				ft_isascii(char *str);
int				ft_isprint(char *str);
int				ft_strlen(char *str);
int				ft_atoi(char *str);
char			*ft_strdup(char *src);
unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size);

#endif

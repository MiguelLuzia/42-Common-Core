/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitavare <mitavare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 09:07:45 by mitavare          #+#    #+#             */
/*   Updated: 2026/10/22 09:38:06 by mitavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dest_size)
{
	size_t	i;
	size_t	dest_len;

	dest_len = 0;
	while (dest_len < dest_size && dest[dest_len] != '\0')
		dest_len++;
	if (dest_len == dest_size)
		return (ft_strlen(src) + dest_len);
	i = 0;
	while (src[i] && i + dest_len < dest_size - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (ft_strlen(src) + dest_len);
}

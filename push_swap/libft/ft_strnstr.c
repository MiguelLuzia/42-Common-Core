/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitavare <mitavare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 11:14:09 by mitavare          #+#    #+#             */
/*   Updated: 2026/10/22 11:57:56 by mitavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *to_find, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	if (to_find[0] == 0)
		return ((char *)s);
	while (s[i] && (i < len))
	{
		n = 0;
		while ((i + n < len) && s[i + n] == to_find[n])
		{
			n++;
			if (!to_find[n])
				return ((char *)(s + i));
		}
		i++;
	}
	return (NULL);
}

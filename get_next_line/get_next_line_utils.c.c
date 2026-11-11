/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitavare <mitavare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 14:59:49 by mitavare          #+#    #+#             */
/*   Updated: 2026/11/11 18:03:52 by mitavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == 0 && *s == 0)
		return ((char *)s);
	return (NULL);
}

static void	ft_copy(const char *src, char *dest, size_t *i)
{
	size_t	j;

	j = 0;
	while (src[j])
	{
		dest[*i] = src[j];
		(*i)++;
		j++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	size;
	char	*str;

	i = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(size + 1);
	if (!str)
		return (str);
	ft_copy(s1, str, &i);
	ft_copy(s2, str, &i);
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	size_t	i;
	char	*copy;

	copy = malloc(ft_strlen(src) + 1);
	if (!copy)
		return (copy);
	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}
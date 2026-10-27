/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitavare <mitavare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 11:57:16 by mitavare          #+#    #+#             */
/*   Updated: 2026/10/27 12:22:01 by mitavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static size_t	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	free_words(char **words, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
		free(words[i++]);
	free(words);
}

static int	fill_words(char const *s, char c, char **words)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			len = word_len(&s[i], c);
			words[j] = malloc(len + 1);
			if (!words[j])
				return (free_words(words, j), 0);
			ft_memcpy(words[j], &s[i], len);
			words[j++][len] = '\0';
			i += len;
		}
	}
	words[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**words;

	words = malloc((count_words(s, c) + 1) * sizeof(*words));
	if (!words)
		return (NULL);
	if (!fill_words(s, c, words))
		return (NULL);
	return (words);
}

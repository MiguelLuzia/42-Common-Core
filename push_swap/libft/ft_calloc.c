/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitavare <mitavare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 11:27:07 by mitavare          #+#    #+#             */
/*   Updated: 2026/10/22 11:54:55 by mitavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	ss;
	void	*a;

	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (NULL);
	ss = nmemb * size;
	a = malloc(ss);
	if (!a)
		return (a);
	ft_bzero(a, ss);
	return (a);
}

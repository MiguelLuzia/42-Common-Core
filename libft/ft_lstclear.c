/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitavare <mitavare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 14:43:54 by mitavare          #+#    #+#             */
/*   Updated: 2026/10/28 14:43:54 by mitavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem;
	t_list	*next;

	if (!lst)
		return ;
	elem = *lst;
	while (elem != NULL)
	{
		next = elem->next;
		del(elem->content);
		free(elem);
		elem = next;
	}
	*lst = NULL;
}
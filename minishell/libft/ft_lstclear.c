/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:15:47 by ooz               #+#    #+#             */
/*   Updated: 2022/03/31 15:15:29 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !(*lst) || !del)
		return ;
	while (*lst)
	{
		tmp = *lst;
		while (tmp->next && tmp->next->next)
			tmp = tmp->next;
		if (tmp->next == NULL)
			break ;
		ft_lstdelone(ft_lstlast(*lst), del);
		tmp->next = NULL;
	}
	ft_lstdelone(ft_lstlast(*lst), del);
	*lst = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysay <ysay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:37:03 by ysay              #+#    #+#             */
/*   Updated: 2022/01/04 12:48:31 by ysay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*l;
	t_list	*n;

	if (!lst)
		return ;
	l = *lst;
	while (l)
	{
		n = l->next;
		ft_lstdelone(l, del);
		l = n;
	}
	*lst = 0;
}

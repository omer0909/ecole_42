/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:15:56 by ooz               #+#    #+#             */
/*   Updated: 2022/01/03 12:15:56 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*new;

	if (lst == NULL || f == NULL)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (new == 0)
	{
		del(&(lst->content));
		new = ft_lstmap(lst->next, f, del);
	}
	else
		new->next = ft_lstmap(lst->next, f, del);
	return (new);
}

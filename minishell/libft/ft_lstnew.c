/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:15:57 by ooz               #+#    #+#             */
/*   Updated: 2022/01/03 12:15:57 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content)
{
	t_list	*r;

	r = (t_list *)malloc(sizeof(t_list));
	if (!r)
		return (NULL);
	r->content = (void *)content;
	r->next = NULL;
	return (r);
	return (NULL);
}

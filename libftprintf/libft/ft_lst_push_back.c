/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:47:21 by jallen            #+#    #+#             */
/*   Updated: 2019/03/07 14:47:32 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lst_push_back(t_list **lst, void *content, size_t content_size)
{
	t_list		*tmp;

	if (*lst)
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = ft_lstnew(content, content_size)))
			return (NULL);
		tmp = tmp->next;
	}
	else
	{
		if (!(*lst = ft_lstnew(content, content_size)))
			return (NULL);
		tmp = *lst;
	}
	return (tmp);
}

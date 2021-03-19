/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <adelille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 13:31:45 by user42            #+#    #+#             */
/*   Updated: 2021/03/19 21:02:35 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(int))
{
	t_list	*first;
	t_list	*new;

	if (!f || !lst)
		return (NULL);
	first = NULL;
	while (lst)
	{
		if (!(new = ft_lstnew((int)(*f)(lst->data))))
		{
			ft_lstclear(&first);
			return (NULL);
		}
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
}

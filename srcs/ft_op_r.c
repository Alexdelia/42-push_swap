/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:34:53 by adelille          #+#    #+#             */
/*   Updated: 2021/03/22 16:48:20 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_r(t_list **lst)
{
	t_list	*tmp;

	if (!lst || !lst->next)
		return (0);
	tmp = lst;
	ft_lstadd_back(&lst, ft_lstnew(lst->data));
	lst = lst->next;
	ft_lstdelone(&tmp);
	return (0);
}

int	ft_rr(t_list **lst)
{
	t_list	*tmp;
	int		data;

	if (!lst || !lst->next)
		return (0);
	tmp = lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	data = tmp->data;
	ft_lstdelone(&tmp);
	ft_lstaddfront(&lst, ft_lstnew(data));
	return (0);
}

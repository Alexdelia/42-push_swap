/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:34:53 by adelille          #+#    #+#             */
/*   Updated: 2021/03/24 04:38:31 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_op_r(t_list **lst)
{
	t_list	*tmp;

	if (lst == NULL || (*lst) == NULL || (*lst)->next == NULL)
		return (0);
	tmp = *lst;
	ft_lstadd_back(lst, ft_lstnew(tmp->data));
	*(lst) = (*lst)->next;
	ft_lstdelone(tmp);
	return (0);
}

int	ft_op_rr(t_list **lst)
{
	t_list	*f;
	t_list	*tmp;
	int		data;

	if (lst == NULL || (*lst) == NULL || (*lst)->next == NULL)
		return (0);
	f = *lst;
	tmp = NULL;
	while (f->next)
	{
		tmp = f;
		f = f->next;
	}
	data = f->data;
	if (tmp != NULL)
		tmp->next = NULL;
	ft_lstdelone(f);
	ft_lstadd_front(lst, ft_lstnew(data));
	return (0);
}

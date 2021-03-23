/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 15:27:35 by adelille          #+#    #+#             */
/*   Updated: 2021/03/23 22:05:59 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_s(t_list **lst)
{
	t_list	*next;
	t_list	*tmp;
	int		data;

	next = *lst;
	next = next->next;
	tmp = *lst;
	if (!lst || !next)
		return (0);
	data = tmp->data;
	tmp->data = next->data;
	next->data = tmp->data;
	*lst = tmp;
	return (0);
}

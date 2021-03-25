/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 15:34:32 by adelille          #+#    #+#             */
/*   Updated: 2021/03/24 03:50:52 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_op_p(t_list **dst, t_list **src)
{
	t_list	*tmp;

	if (src == NULL || (*src) == NULL)
		return (0);
	tmp = *src;
	ft_lstadd_front(dst, ft_lstnew(tmp->data));
	*(src) = (*src)->next;
	ft_lstdelone(tmp);
	return (0);
}

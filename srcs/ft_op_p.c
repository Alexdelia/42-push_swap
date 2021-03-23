/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 15:34:32 by adelille          #+#    #+#             */
/*   Updated: 2021/03/23 22:24:19 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_p(t_list *dst, t_list *src)
{
	t_list	*tmp;

	if (!src)
		return (0);
	ft_lstadd_front(&dst, ft_lstnew(src->data));
	tmp = src;
	src = src->next;
	ft_lstdelone(tmp);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mt_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 22:35:37 by adelille          #+#    #+#             */
/*   Updated: 2021/05/03 22:46:27 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_mt_s(t_markup *mt, int type)
{
	t_mt	*tmp;

	if (type == MT_A)
	{
		if (mt->a == NULL || mt->a->next == NULL)
			return ;
		tmp = mt->a;
		mt->a = tmp->next;
		tmp->next = tmp->next->next;
		mt->a->next = tmp;
	}
	else if (type == MT_B)
	{
		if (mt->b == NULL || mt->b->next == NULL)
			return ;
		tmp = mt->b;
		mt->b = tmp->next;
		tmp->next = tmp->next->next;
		mt->b->next = tmp;
	}
}

void	ft_mt_ss(t_markup *mt)
{
	ft_mt_s(mt, MT_A);
	ft_mt_s(mt, MT_B);
}

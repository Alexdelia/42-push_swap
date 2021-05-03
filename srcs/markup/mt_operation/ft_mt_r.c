/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mt_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 22:50:14 by adelille          #+#    #+#             */
/*   Updated: 2021/05/03 22:57:17 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_mt_r(t_markup *mt, int type)
{
	t_mt	*tmp;

	if (type == MT_A)
	{
		tmp = mt->a;
		mt->a = mt->a->next;
		ft_mt_addback(&mt->a, ft_mt_new(tmp->nb, tmp->index, tmp->keep));
	}	
	else if (type == MT_B)
	{
		tmp = mt->b;
		mt->b = mt->b->next;
		ft_mt_addback(&mt->b, ft_mt_new(tmp->nb, tmp->index, tmp->keep));
	}
	ft_mt_free(tmp);
}

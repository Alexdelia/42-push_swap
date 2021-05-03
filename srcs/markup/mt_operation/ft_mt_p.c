/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mt_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 22:46:36 by adelille          #+#    #+#             */
/*   Updated: 2021/05/03 22:50:05 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_mt_p(t_markup *mt, int type)
{
	t_mt	*tmp;

	if (type == MT_A)
	{
		tmp = mt->a;
		mt->a = mt->b;
		mt->a->next = tmp;
		mt->b = mt->b->next;
	}
	else if (type == MT_B)
	{
		tmp = mt->b;
		mt->b = mt->a;
		mt->b->next = tmp;
		mt->a = mt->a->next;
	}
}

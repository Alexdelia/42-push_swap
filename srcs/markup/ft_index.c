/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 15:01:44 by adelille          #+#    #+#             */
/*   Updated: 2021/07/21 22:47:24 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static t_mt	*ft_next_min(t_markup *ma)
{
	int		i;
	int		b_min;
	t_mt	*min;
	t_mt	*tmp;

	min = NULL;
	if (ma)
	{
		i = 0;
		b_min = FALSE;
		tmp = ma->head;
		while (i < ma->size)
		{
			if ((tmp->index == -1) && (!b_min || tmp->nb < min->nb))
			{
				b_min = TRUE;
				min = tmp;
			}
			i++;
			tmp = tmp->next;
		}
	}
	return (min);
}

void	ft_index(t_markup *ma)
{
	int		index;
	t_mt	*mt;

	index = 0;
	mt = ft_next_min(ma);
	while (mt)
	{
		mt->index = index++;
		mt = ft_next_min(ma);
	}
}

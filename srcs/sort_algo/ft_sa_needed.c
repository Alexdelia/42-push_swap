/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa_needed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:50:19 by adelille          #+#    #+#             */
/*   Updated: 2021/05/19 19:06:59 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_total_keep(t_mt *mt)
{
	int	keep;

	keep = 0;
	while (mt)
	{
		if (mt->keep == TRUE)
			keep++;
		mt = mt->next;
	}
	return (keep);
}

int	ft_sa_needed(t_markup *mt)
{
	int	total_keep_before;
	int	tolal_keep_after;

	total_keep_before = ft_total_keep(mt->a);
	ft_mt_s(mt, MT_A);
	total_keep_after = ft_total_keep(mt->a);
	ft_mt_s(mt, MT_A);
	if (total_keep_after > total_keep_before)
		return (TRUE);
	return (FALSE);
}

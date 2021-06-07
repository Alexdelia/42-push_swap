/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 22:44:56 by adelille          #+#    #+#             */
/*   Updated: 2021/06/07 23:01:31 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_align_smallest(t_mt *a)
{
	int	smallest;

	smallest = INT_MAX;
	while (a)
	{
		if (a->nb < smallest)
			smallest = a->nb;
		a = a->next;
	}
	return (smallest);
}

int	ft_align_smallest_i(t_mt *a)
{
	int	smallest;
	int	i;

	i = 0;
	smallest = ft_align_smallest(a);
	while (a->nb != smallest)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int	ft_align_a(t_markup *ma, int print)
{
	int	res;
	int	smallest;

	res = 0;
	smallest = ft_align_smallest(ma->a);
	if (ft_align_smallest_i(ma->a) <= ft_mt_size(ma->a) / 2)
	{
		while (ma->a->nb != smallest)
		{
			ft_mt_r(ma, MT_A);
			res += ft_update_command("ra\n", print, 1);
		}
	}
	else
	{
		while (ma->a->nb != smallest)
		{
			ft_mt_rr(ma, MT_A);
			res += ft_update_command("rra\n", print, 1);
		}
	}
	return (res);
}

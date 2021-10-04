/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:07:58 by adelille          #+#    #+#             */
/*   Updated: 2021/10/04 21:34:47 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void	ft_init_solve(t_data *d)
{
	d->big = ft_biggest_loop(d->a, 1);
	d->size = ft_stacklen(d->a);
	d->group_count = ft_max(1, (int)(d->max / 150.0));
	d->group_size = d->max / d->ground_count;
}

void	ft_solve(t_data *d, int group)
{
	int	distance;

	ft_init_solve(d);
	while (d->size >= d->big && group <= (d->group_count + 1))
	{
		d->tmp = ft_nearest_in_group(d->a, group, d->group_size);
		if (d->tmp == NULL && ++ group)
				continue ;
		distance = ft_distance_to_top(d->a, d->tmp->index);
		if (d->a && ft_can_swap(d->a))// to code
		{
			ft_sa(d);
			d->big = ft_biggest_loop(d->a, 1);
		}
		else if (d->a && !d->a->keep && distance == 0)
		{
			ft_pb(d);
			(d->size)--;
		}
		else if (d->group_count == 1)
			ft_rrr(d);
		else
			ft_rotate(d, ft_min(1, ft_max(-1, distance)), 0); // to code
	}
	//
}

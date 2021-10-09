/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:07:58 by adelille          #+#    #+#             */
/*   Updated: 2021/10/09 19:27:44 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_can_swap(t_stack *s)
{
	t_stack	s1;
	t_stack	s2;
	int		i1;
	int		i2;

	s1.next = &s2;
	s1.index = s->next->index;
	s2.next = s->next->next;
	s2.index = s->index;
	i1 = ft_biggest_loop(s, 0);
	i2 = ft_biggest_loop(&s1, 0);
	if (i2 > i1)
		return (TRUE);
	return (FALSE);
}

static void	ft_init_solve(t_data *d)
{
	d->big = ft_biggest_loop(d->a, 1);
	d->size = ft_stacklen(d->a);
	d->group_count = ft_max(1, (int)(d->max / 150.0));
	d->group_size = d->max / d->group_count;
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
		if (d->a && ft_can_swap(d->a))
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
			ft_rotator(d, ft_min(1, ft_max(-1, distance)), 0);
	}
	ft_push_back_to_a(d);
}

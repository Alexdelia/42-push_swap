/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 18:44:54 by adelille          #+#    #+#             */
/*   Updated: 2021/10/01 18:52:13 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int		ft_has_index(t_stack *s, int index)
{
	while (s)
	{
		if (s->index == index)
			return (TRUE);
		s = s->next;
	}
	return (FALSE);
}

void	ft_solve_5(t_data *d)
{
	t_stack	*s;
	int		min;
	int		distance;

	while (ft_has_index(d->a, 0) || ft_had_index(d->a, d->max - 1))
	{
		s = d->a;
		min = INT_MAX;
		while (s)
		{
			if (s->index == 0 || s->index == d->max - 1)
			{
				distance = ft_distance_to_top(d->a, s->index); // to code
				if (ft_abs(distance) < ft_abs(min))
					min = distance;
			}
			s = s->next;
		}
		if (min == 0)
			ft_pb(d);
		else if (min < 0)
			ft_rra(d);
		else if (min > 0)
			ft_ra(d);
	}
}

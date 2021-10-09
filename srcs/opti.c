/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 22:06:54 by adelille          #+#    #+#             */
/*   Updated: 2021/10/09 19:28:32 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_stacklen(t_stack *s)
{
	int	i;

	i = 0;
	while (s)
	{
		i++;
		s = s->next;
	}
	return (i);
}

int	ft_distance_to_top(t_stack *a, int index)
{
	int	i;
	int	size;

	i = 0;
	size = ft_stacklen(a);
	while (a)
	{
		if (a->index == index)
			break ;
		a = a->next;
		i++;
	}
	if (i > size / 2)
		i -= size;
	return (i);
}

int	ft_distance_to_index(int index, int size)
{
	if (index >= size / 2)
		index -= size;
	return (index);
}

t_stack	*ft_nearest_in_group(t_stack *s, int group, int group_size)
{
	t_stack	*nearest;
	t_stack	*t;
	int		small_distance;
	int		distance;

	small_distance = INT_MAX;
	nearest = NULL;
	t = s;
	while (t)
	{
		if (t->index <= group_size * group && !t->keep)
		{
			distance = ft_distance_to_top(s, t->index);
			if (ft_abs(distance) < ft_abs(small_distance))
			{
				small_distance = distance;
				nearest = t;
				if (small_distance == 0)
					break ;
			}
		}
		t = t->next;
	}
	return (nearest);
}

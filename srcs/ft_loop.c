/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:07:08 by adelille          #+#    #+#             */
/*   Updated: 2021/10/04 21:19:36 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_loop_stack(t_stack *s, t_stack *start, int set)
{
	t_stack	*loop;
	int		max_index;
	int		i;

	max_index = -1;
	i = 0;
	loop = start;
	while (loop)
	{
		if (set)
				loop->keep = 0;
		if (loop->index > max_index)
		{
			max_index = loop->index;
			i++;
			if (set)
				loop->keep = 1;
		}
		loop = loop->next;
		if (loop == NULL)
			loop = s;
		if (loop == start)
			break;
	}
	return (i);
}

int	ft_biggest_loop(t_stack *start, int set)
{
	t_stack	*s;
	t_stack	*keep;
	int		max;
	int		count;

	max = 0;
	s = start;
	while (s)
	{
		count = ft_loop_stack(start, s, 0);
		if (count > max)
		{
			max = count;
			keep = s;
		}
		s = s->next;
	}
	if (set)
			ft_loop_stack(start, keep, 1);
	return (max);
}

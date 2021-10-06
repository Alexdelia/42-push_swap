/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back_to_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:44:44 by adelille          #+#    #+#             */
/*   Updated: 2021/10/06 15:57:41 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_insert_distance(t_stack *s, int t, int size)
{
	t_stack	*p;
	t_stack	*c;
	int		c_max[2];
	int		i;

	i = 0;
	p = ft_get_last(s);
	c = s;
	c_max[1] = INT_MAX;
	while (c)
	{
		if ((p->index > c->index && (t < c->index || t > p->index))
				|| (t > p->index && t < c->index))
		{
			c_max[0] = i;
			if (c_max[0] > size / 2)
				c_max[0] -= size;
			if (ft_abs(c_max[0]) < c_max[1])
				c_max[1] = c_max[0];
		}
		p = c;
		c = c->next;
		i++;
	}
	return (c_max[1]);
}

void	ft_opti_rotate_b(t_data *d, int max_distance, int *ra, int *rb)
{
	int	total_distance;
	int	insert;
	int	b_distance;
	int	i;

	i = 0;
	d->tmp = d->b;
	while (d->tmp)
	{
		b_distance = ft_distance_to_index(i++, d->max - d->size);
		insert = ft_insert_distance(d->a, d->tmp->index, d->size);
		total_distance = ft_abs(insert) + ft_abs(b_distance);
		if (insert > 0 && b_distance > 0)
			total_distance -= ft_min(b_distance, insert);
		if (insert < 0 && b_distance < 0)
			total_distance += ft_max(b_distance, insert);
		if (total_distance < max_distance)
		{
			max_distance = total_distance;
			*ra = insert;
			*rb = b_distance;
		}
		d->tmp = d->tmp->next;
	}
}

void	ft_push_back_to_a(t_data *d)
{
	int	ra;
	int	rb;

	while (d->b)
	{
		ft_opti_rotate_b(d, INT_MAX, &ra, &rb);
		ft_rotator(d, ra, rb);
		ft_pa(d);
		(d->size)++;
	}
	ft_rotator(d, ft_distance_to_top(d->a, 0), 0);
}

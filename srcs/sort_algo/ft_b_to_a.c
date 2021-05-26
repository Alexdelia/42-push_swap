/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:35:25 by adelille          #+#    #+#             */
/*   Updated: 2021/05/26 18:21:11 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_b_to_a	ft_init_f(void)
{
	t_b_to_a	f;

	f.b = 0;
	f.a = 0;
	f.r = 0;
	return (f);
}

int	ft_max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

int	ft_suitable_a(t_mt *a, int b)
{
	int	over;
	int	v;

	over = INT_MAX;
	v = FALSE;
	while (a)
	{
		if (a->nb < over && a->nb > b)
		{
			under = a->nb;
			v = TRUE;
		}
	}
	if (v == FALSE)
		return (b);
	return (under);
}

int	ft_i_suitable_a(t_mt *a, int b)
{
	int	i;
	int	suitable;

	i = 0;
	suitable = ft_suitable_a(a, b);
	while (a && a->nb != suitable)
	{
		i++;
		a = a->next;
	}
	return (i);
}

t_b_to_a	ft_b_to_a_best(t_markup ma, t_b_to_a f)
{
	int total;
	int	actual;
	int	i_a;
	int	i_b;
	int	size_b;
	int	size_a;
	int	r;

	total = INT_MAX;
	size_b = ft_mt_size(ma.b);
	size_a = ft_mt_size(ma.a);
	i_b = 0;
	while (ma.b)
	{
		if (ft_suitable_a(ma.a, ma.b->nb) != ma.b->nb)
		{
			r = 0;
			i_a = ft_i_suitable_a(ma.a, ma.b->nb);
			if ((i_a >= size_a / 2 && i_b >= size_b / 2)
					|| i_a < size_a / 2 && i_b < size_b / 2)
			{
				r = R_UP;
				if (i_a >= size_a / 2 && i_b >= size_b / 2)
				{
					i_a -= size_a / 2;
					i_b -= size_b / 2;
					r = R_DOWN;
				}
				actual = ft_max(i_a, i_b);
			}
			else
			{
				if (i_a >= size_a / 2)
					i_a -= size_a / 2;
				if (i_b >= size_b / 2)
					i_b -= size_b / 2;
				actual = i_a + i_b;
			}
			if (actual < total)
			{
				total = actual;
				f.b = ma.b->nb;
				f.a = ft_suitable_a(ma.a, ma.b->nb);
				f.r = r;
			}
			i_b++;
			ma.b = ma.b->next;
		}
	}
	return (f);
}

int	ft_b_to_a_move(t_markup *ma, t_b_to_a f)
{

}

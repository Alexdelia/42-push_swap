/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_direction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 17:23:04 by adelille          #+#    #+#             */
/*   Updated: 2021/07/20 15:48:50 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static t_mt	*ft_find_mt_a(t_markup *a, int index)
{
	t_mt	*mt;

	mt = a->markup_head;
	if (index < mt->index)
	{
		while (index < mt->prev->index && mt->index > mt->prev->index)
			mt = mt->prev;
	}
	else
	{
		while (index > mt->index && mt->index < mt->next->index)
			mt = mt->next;
		if (index > mt->index && mt->index > mt->next->index)
			mt = mt->next;
	}
	return (mt);
}

static void	ft_process_dir(t_markup *ma, int index, int *rx, int *rrx)
{
	t_mt	*current;

	if (ma && ma->head)
	{
		current = ma->head;
		while (current->index != index)
		{
			(*rx)++;
			current = current->next;
		}
		current = ma->head;
		while (current->index != index)
		{
			(*rrx)++;
			current = current->prev;
		}
	}
}

static void	ft_set_dir(int size, t_sbs new_sbs, t_sbs *sbs)
{
	if (sbs->set == FALSE || size < sbs->size)
	{
		sbs->mt_a = new_sbs.mt_a;
		sbs->mt_b = new_sbs.mt_b;
		sbs->dir_a = new_sbs.dir_a;
		sbs->dir_b = new_sbs.dir_b;
		sbs->size = size;
		sbs->set = TRUE;
	}
}

static void	ft_optimal_dir(t_markup *a, t_markup *b, t_mt *mt_b, t_sbs *sbs)
{
	t_sbs	new_sbs;
	t_rxs	r;

	r.ra = 0;
	r.rra = 0;
	r.rb = 0;
	r.rrb = 0;
	new_sbs.mt_a = ft_find_mt_a(a, mt_b->index);
	new_sbs.mt_b = mt_b;
	ft_process_dir(a, new_sbs.mt_a->index, &r.ra, &r.rra);
	ft_process_dir(b, new_sbs.mt_b->index, &r.rb, &r.rrb);
	new_sbs.dir_a = R_UP;
	new_sbs.dir_b = R_UP;
	ft_set_dir(ft_max(r.ra, r.rb), new_sbs, sbs);
	new_sbs.dir_a = R_DOWN;
	ft_set_dir(r.rra + r.rb, new_sbs, sbs);
	new_sbs.dir_b = R_DOWN;
	ft_set_dir(ft_max(r.rra, r.rrb), new_sbs, sbs);
	new_sbs.dir_a = R_UP;
	ft_set_dir(r.ra + r.rrb, new_sbs, sbs);
}

void	ft_find_dir(t_markup *a, t_markup *b, t_sbs *sbs)
{
	int		i;
	t_mt	*current;

	if (b)
	{
		i = 0;
		current = b->head;
		while (i < b->size)
		{
			ft_optimal_dir(a, b, current, sbs);
			i++;
			current = current->next;
		}
	}
}

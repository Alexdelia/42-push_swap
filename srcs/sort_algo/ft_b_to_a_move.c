/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b_to_a_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:16:03 by adelille          #+#    #+#             */
/*   Updated: 2021/05/31 15:39:56 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_move_up_b_to_a(t_markup *ma, t_b_to_a f, print)
{
	int	operation;

	operation = 0;
	while (ma->a->nb != f.a && ma->b->nb != f.b)
	{
		ft_mt_r(ma, MT_A);
		ft_mt_r(ma, MT_B);
		operation += ft_update_command("rr\n", print, 1);
	}
	while (ma->a->nb != f.a)
	{
		ft_mt_r(ma, MT_A);
		operation += ft_update_command("ra\n", print, 1);
	}
	while (ma->b->nb != f.b)
	{
		ft_mt_r(ma, MT_B);
		operation += ft_update_command("rb\n", print, 1);
	}
	return (operation);
}

int	ft_move_down_b_to_a(t_markup *ma, t_b_to_a f, print)
{
	int	operation;

	operation = 0;
	while (ma->a->nb != f.a && ma->b->nb != f.b)
	{
		ft_mt_rr(ma, MT_A);
		ft_mt_rr(ma, MT_B);
		operation += ft_update_command("rrr\n", print, 1);
	}
	while (ma->a->nb != f.a)
	{
		ft_mt_rr(ma, MT_A);
		operation += ft_update_command("rra\n", print, 1);
	}
	while (ma->b->nb != f.b)
	{
		ft_mt_rr(ma, MT_B);
		operation += ft_update_command("rrb\n", print, 1);
	}
	return (operation);
}

int	ft_find_close(t_mt *x, int nb)
{
	int	i;
	int size;

	i = 0;
	while (x && x->nb != nb)
	{
		x = x->next;
		i++;
	}
	size = i;
	while (x)
	{
		x = x->next;
		size++;
	}
	if (i >= size / 2)
		return (R_DOWN);
	return (R_UP);
}

int	ft_move_find_b_to_a(t_markup *ma, t_b_to_a f, int print)
{
	int	operation;

	operation = 0;
	if (ft_find_close(ma->a, f.a) == R_UP)
	{
		while (ma->a->nb != f.a)
		{
			ft_mt_r(ma, MT_A);
			operation += ft_update_command("ra\n", print, 1);
		}
	}
	else
	{
		while (ma->a->nb != f.a)
		{
			ft_mt_rr(ma, MT_A);
			operation += ft_update_command("rra\n", print, 1);
		}
	}
	if (ft_find_close(ma->b, f.b) == R_UP)
	{
		while (ma->b->nb != f.b)
		{
			ft_mt_r(ma, MT_B);
			operation += ft_update_command("rb\n", print, 1);
		}
	}
	else
	{
		while (ma->b->nb != f.b)
		{
			ft_mt_rr(ma, MT_B);
			operation += ft_update_command("rrb\n", print, 1);
		}
	}
	return (operation);
}

int	ft_b_to_a_move(t_markup *ma, t_b_to_a f, int print)
{
	int	operation;

	operation = 0;
	if (f.r == R_UP)
		operation = ft_move_up_b_to_a(ma, f, print);
	else if (f.r == R_DOWN)
		operation = ft_move_down_b_to_a(ma, f, print);
	else
		operation = ft_move_find_b_to_a(ma, f, print);
	return (operation);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 11:51:55 by adelille          #+#    #+#             */
/*   Updated: 2021/03/29 11:52:08 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_first_chunk(t_arg *arg, int data)
{
	int	n_command;

	n_command = 0;
	if (data == 2)
	{
		if (arg->b->data < arg->b->next->data)
		{
			ft_op_sb(arg);
			ft_ps("sb\n");
			n_command++;
		}
		ft_op_p(&arg->a, &arg->b);
		ft_op_p(&arg->a, &arg->b);
		ft_ps("pa\npa\n");
		return (2 + n_command);
	}
	ft_op_p(&arg->a, &arg->b);
	ft_ps("pa\n");
	return (1);
}

int	ft_mid_chunk_loop(t_arg *arg, int n_command, int n_r)
{
	int	next_big;

	next_big = ft_biggest(arg->b);
	while (arg->b->data != next_big)
	{
		ft_op_r(&arg->b);
		ft_ps("rb\n");
		n_command++;
		n_r++;
	}
	ft_op_p(&arg->a, &arg->b);
	ft_ps("pa\n");
	while (n_r > 0)
	{
		ft_op_rr(&arg->b);
		ft_ps("rrb\n");
		n_command++;
		n_r--;
	}
	return (n_command);
}

int	ft_mid_chunk(t_arg *arg, int data)
{
	int	n_command;

	n_command = 0;
	while (data > 2)
	{
		n_command += ft_mid_chunk_loop(arg, n_command, 0);
		data--;
	}
	return (n_command + ft_first_chunk(arg, 2));
}

int	ft_last_chunk(t_arg *arg, int data)
{
	int	n_command;
	int	next_big;

	n_command = 0;
	while (data > 2)
	{
		next_big = ft_biggest(arg->b);
		n_command += ft_opti_top(&arg->b, next_big, TRUE, "b\n");
		ft_op_p(&arg->a, &arg->b);
		ft_ps("pa\n");
		n_command++;
		data--;
	}
	return (n_command + ft_first_chunk(arg, 2));
}

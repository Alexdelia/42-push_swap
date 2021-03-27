/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 00:31:33 by adelille          #+#    #+#             */
/*   Updated: 2021/03/27 02:06:21 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_r_to_bot(t_arg *arg, int SmA, int BiB, int v)
{
	int	n_command;

	n_command = 0;
	while (ft_lst_last(arg->a, SmA) == FALSE && ft_lst_last(arg->b, BiB) == FALSE)
	{
		n_command += ft_need_ss(arg, v);
		if (ft_lst_last(arg->a, SmA) == TRUE)
		{
			ft_op_r(&arg->b);
			if (v == TRUE)
				ft_ps("rb\n");
			n_command++;
		}
		else if (ft_lst_last(arg->b, BiB) == TRUE)
		{
			ft_op_r(&arg->a);
			if (v == TRUE)
				ft_ps("ra\n");
			n_command++;
		}
		else
		{
			ft_op_r(&arg->a);
			ft_op_r(&arg->b);
			if (v == TRUE)
				ft_ps("rr\n");
			n_command++;
		}
	}
	return (n_command);
}

int	ft_need_ss(t_arg *arg, int v)
{
	if (arg->a && arg->a->next && arg->a->data > arg->a->next->data
			&& arg->b &arg->b->next && arg->b->data < arg->b->next->data)
	{
		ft_op_sa(arg);
		ft_op_sb(arg);
		if (v == TRUE)
			ft_ps("ss\n");
		return (1);
	}
	return (0);
}

int	ft_alex_sort(t_arg arg, int v)
{
	int	n_command;
	int	next_big;
	int	next_small;

	n_command = ft_separate(&arg, v);
	next_big = ft_biggest(arg.b);
	next_small = ft_smallest(arg.a);
	n_command += ft_r_to_bot(&arg, next_small, next_big, v);
	while (ft_check_sort(arg.b) == FALSE && ft_check_unsort(arg.a) == FALSE)
	{
		n_command += ft_need_ss(&arg, v);
		if (ft_chek_sort(arg.b) == FALSE && ft_check_unsort(arg.b) == FALSE)
		{
			next_big = ft_next_big(arg.b, next_big);
			n_command += ft_opti_top(&arg.b, next_big, v, "b\n");
			ft_op_p(&arg.b, &arg.a);
			if (v == TRUE)
				ft_ps("pb\n");
			n_command++;
		}
	}
}

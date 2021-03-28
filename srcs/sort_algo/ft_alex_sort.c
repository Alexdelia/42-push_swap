/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 00:31:33 by adelille          #+#    #+#             */
/*   Updated: 2021/03/28 07:27:57 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

/*void	ft_pl(t_arg arg)
{
	ft_ps("\na:\t");
	while (arg.a)
	{
		ft_ps(ft_itoa(arg.a->data));
		ft_ps(" ");
		arg.a = arg.a->next;
	}
	ft_ps("\nb:\t");
	while (arg.b)
	{
		ft_ps(ft_itoa(arg.b->data));
		ft_ps(" ");
		arg.b = arg.b->next;
	}
	ft_ps("\n");
}*/

int	ft_need_ss(t_arg *arg, int v)
{
	if (arg->a && arg->a->next && arg->a->data > arg->a->next->data
			&& arg->b && arg->b->next && arg->b->data < arg->b->next->data)
	{
		ft_op_sa(arg);
		ft_op_sb(arg);
		if (v == TRUE)
			ft_ps("ss\n");
		return (1);
	}
	return (0);
}

int	ft_r_to_top(t_arg *arg, int SmA, int BiB, int v)
{
	int	n_command;

	n_command = 0;
	while (arg->a->data != SmA || arg->b->data != BiB)
	{
		n_command += ft_need_ss(arg, v);
		if (arg->a->data == SmA)
		{
			ft_op_r(&arg->b);
			if (v == TRUE)
				ft_ps("rb\n");
			n_command++;
		}
		else if (arg->b->data == BiB)
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

int	ft_alex_sort(t_arg arg, int v)
{
	int	n_command;
	int	next_big;
	int	old_big;
	int	next_small;
	int old_small;
	int	do_ra;
	int	do_rb;

	n_command = ft_separate(&arg, v);
	next_big = ft_biggest(arg.b);
	next_small = ft_smallest(arg.a);
	n_command += ft_r_to_top(&arg, next_small, next_big, v);
	do_ra = FALSE;
	do_rb = FALSE;
	while (ft_check_sort(arg.a) == FALSE || ft_check_unsort(arg.b) == FALSE)
	{
		n_command += ft_need_ss(&arg, v);
		if (ft_check_sort(arg.a) == TRUE && ft_check_unsort(arg.b) == FALSE)
		{
			next_big = ft_biggest(arg.b);
			n_command += ft_opti_top(&arg.b, next_big, v, "b\n");
			next_big = ft_next_big(arg.b, next_big);
			ft_op_p(&arg.a, &arg.b);
			if (v == TRUE)
				ft_ps("pa\n");
			n_command++;
		}
		if (ft_check_unsort(arg.b) == FALSE)
		{
			n_command += ft_opti_top(&arg.b, next_big, v, "b\n");
			old_big = next_big;
			next_big = ft_next_big(arg.b, next_big);
			ft_op_p(&arg.a, &arg.b);
			if (v == TRUE)
				ft_ps("pa\n");
			n_command++;
			n_command += ft_opti_bot(&arg.b, next_big, v, "b\n");
			ft_op_p(&arg.b, &arg.a);
			if (v == TRUE)
				ft_ps("pb\n");
			do_rb = TRUE;
		}
		if (ft_check_sort(arg.a) == FALSE)
		{
			n_command += ft_opti_top(&arg.a, next_small, v, "a\n");
			old_small = next_small;
			next_small = ft_next_small(arg.a, next_small);
			ft_op_p(&arg.a, &arg.b);
			if (v == TRUE)
				ft_ps("pb\n");
			n_command++;
			n_command += ft_opti_bot(&arg.a, next_small, v, "a\n");
			ft_op_p(&arg.b, &arg.a);
			if (v == TRUE)
				ft_ps("pa\n");
			do_ra = TRUE;
		}
		if (do_rb == TRUE && do_ra == TRUE)
		{
			ft_op_r(&arg.a);
			ft_op_r(&arg.b);
			if (v == TRUE)
				ft_ps("rr\n");
			do_ra = FALSE;
			do_rb = FALSE;
			n_command++;
		}
		else if (do_rb == TRUE)
		{
			ft_op_r(&arg.b);
			if (v == TRUE)
				ft_ps("rb\n");
			do_rb = FALSE;
			n_command++;
		}
		else if (do_ra == TRUE)
		{
			ft_op_r(&arg.a);
			if (v == TRUE)
				ft_ps("ra\n");
			do_ra = FALSE;
			n_command++;
		}
	}
	while (arg.b)
	{
		ft_op_p(&arg.a, &arg.b);
		if (v == TRUE)
			ft_ps("pa\n");
	}
	return (n_command);
}

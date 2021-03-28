/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_separate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 02:04:47 by adelille          #+#    #+#             */
/*   Updated: 2021/03/28 09:12:00 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_lst_average(t_list *lst)
{
	int	sum;
	int	i;

	sum = 0;
	i = 0;
	while (lst)
	{
		sum += lst->data;
		i++;
		lst = lst->next;
	}
	return (sum / i);
}

int	ft_is_sep(t_arg arg, int average)
{
	while (arg.a)
	{
		if (arg.a->data < average)
			return (FALSE);
		arg.a = arg.a->next;
	}
	while (arg.b)
	{
		if (arg.b->data >= average)
			return (FALSE);
		arg.b = arg.b->next;
	}
	return (TRUE);
}

int	ft_separate(t_arg *arg, int v)
{
	int	i;
	int	size;
	int	average;

	i = 0;
	size = ft_lstsize(arg->a);
	average = ft_lst_average(arg->a);
	while (i <= size && ft_is_sep(*arg, average) == FALSE)
	{
		if (arg->a->data > average)
		{
			ft_op_r(&arg->a);
			if (v == TRUE)
				ft_ps("ra\n");
		}
		else
		{
			ft_op_p(&arg->b, &arg->a);
			if (v == TRUE)
				ft_ps("pb\n");
		}
		i++;
	}
	return (i);
}

int	ft_advance_separate(t_arg *arg)
{
	int	n_command;
	int	old_size_b;
	int	size;
	int	average;

	n_command = 0;
	old_size_b = ft_lstsize(arg->b);
	size = ft_lstsize(arg->a);
	average = ft_lst_average(arg->a);
	while (ft_lstsize(arg->a) > 2 && (ft_lstsize(arg->b) - old_size_b) < size / 2)
	{
		if (arg->a->data < average)
		{
			ft_op_p(&arg->b, &arg->a);
			ft_ps("pb\n");
		}
		else if (ft_lst_last(arg->a) < average)
		{
			ft_op_rr(&arg->a);
			ft_op_p(&arg->b, &arg->a);
			ft_ps("rra\npb\n");
		}
		else
		{
			ft_op_r(&arg->a);
			ft_ps("raOUI\n");
		}
	}
	ft_lstadd_back(&arg->chunk, ft_lstnew(ft_lstsize(arg->b) - old_size_b));
	return (n_command);
}

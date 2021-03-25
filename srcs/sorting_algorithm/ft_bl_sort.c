/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bl_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 20:22:24 by adelille          #+#    #+#             */
/*   Updated: 2021/03/25 23:57:13 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_bl_sort(t_arg arg, int v)
{
	int	smallest;
	int	value;
	int	i;
	int	sorted;
	int	n_command;
	t_list	*head;

	value = INT_MAX;
	sorted = FALSE;
	n_command = 0;
	while (sorted == TRUE)
	{
		head = arg->a;
		i = 1;
		while (arg->a)
		{
			if (arg->a->data < value)
			{
				value = arg->a->data;
				smallest = i;
			}
			i++;
			arg->a = arg->a->next;
		}
		arg->a = head;
		if (i > (ft_lstsize(a) / 2))
		{
			while (arg->a->data != value)
			{
				ft_op_rr(&arg->a);
				if (v == TRUE)
					ft_ps("rra\n");
				n_command++;
			}
		}
		else
		{
			while (arg->a->data != value)
			{
				ft_op_r(&arg->a);
				if (v == TRUE)
					ft_ps("ra\n");
				n_command++;
			}
		}
		ft_op_p(&arg->b, &arg->a);
		n_command++;
		if (v == TRUE)
			ft_ps("pb\n");
		if (ft_check_sort(arg->a) TRUE)
			sorted == TRUE;
	}
	while (arg->b)
	{
		ft_op_p(&arg->a, &arg->b);
		if (v == TRUE)
			ft_ps("pa\n");
		n_command++;
	}
	return (n_command);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bl_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 20:22:24 by adelille          #+#    #+#             */
/*   Updated: 2021/03/26 00:29:54 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_bl_sort(t_arg arg)
{
	int	smallest;
	int	value;
	int	i;
	int	sorted;
	int	n_command;
	t_list	*head;

	sorted = FALSE;
	n_command = 0;
	while (sorted == FALSE)
	{
		value = INT_MAX;
		head = arg.a;
		i = 1;
		while (arg.a)
		{
			if (arg.a->data < value)
			{
				value = arg.a->data;
				smallest = i;
			}
			i++;
			arg.a = arg.a->next;
		}
		arg.a = head;
		if (i > (ft_lstsize(arg.a) / 2))
		{
			while (arg.a->data != value)
			{
				ft_op_rr(&arg.a);
				ft_ps("rra\n");
				n_command++;
			}
		}
		else
		{
			while (arg.a->data != value)
			{
				ft_op_r(&arg.a);
				ft_ps("ra\n");
				n_command++;
			}
		}
		ft_op_p(&arg.b, &arg.a);
		n_command++;
		ft_ps("pb\n");
		if (ft_check_sort(arg.a) == TRUE)
			sorted = TRUE;
	}
	while (arg.b)
	{
		ft_op_p(&arg.a, &arg.b);
		ft_ps("pa\n");
		n_command++;
	}
	return (n_command);
}

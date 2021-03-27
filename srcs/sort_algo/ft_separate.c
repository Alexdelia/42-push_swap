/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_separate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 02:04:47 by adelille          #+#    #+#             */
/*   Updated: 2021/03/27 02:05:08 by adelille         ###   ########.fr       */
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
		if (arg.a < average)
			return (FALSE);
		arg.a = arg.a->next;
	}
	while (arg.b)
	{
		if (arg.b >= average)
			return (FALSE);
	}
	return (TRUE);
}

int	ft_separate(t_arg *arg, int v)
{
	int	i;
	int	size;
	int	average;

	i = 0;
	size = ft_lst_size(arg->a);
	average = ft_lst_average(arg->a);
	while (i <= size && ft_sep(*arg, average) == FALSE)
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


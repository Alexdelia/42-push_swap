/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 20:28:25 by adelille          #+#    #+#             */
/*   Updated: 2021/07/20 16:00:23 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int	ft_need_pb(t_markup *a)
{
	int		i;
	t_mt	*tmp;

	if (a)
	{
		i = 0;
		tmp = a->head;
		while (i < a->size)
		{
			if (!tmp->keep)
				return (TRUE);
			i++;
			tmp = tmp->next;
		}
	}
	return (FALSE);
}

static int	ft_need_sa(t_markup *a, int (*ft_ma)(t_markup *, t_mt *))
{
	int	pairs;

	if (a && a->size >= 2)
	{
		ft_mt_sx(a, NULL, NULL);
		pairs = ft_ma(a, a->markup_head);
		ft_mt_sx(a, NULL, NULL);
		ft_ma(a, a->markup_head);
		if (pairs > a->pairs)
			return (TRUE);
	}
	return (FALSE);
}

void	ft_solve_a(t_markup *a, t_markup *b,
		int (*ft_ma)(t_markup *, t_mt *), t_arg_list *arg_list)
{
	while (ft_need_pb(a) == TRUE)
	{
		if (ft_need_sa(a, ft_ma) == TRUE)
		{
			ft_mt_sx(a, "sa\n", arg_list);
			a->pairs = ft_ma(a, a->markup_head);
		}
		else if (a->head->keep == FALSE)
			ft_mt_p(b, a, "pb\n", arg_list);
		else
			ft_mt_rx(a, "ra\n", arg_list);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 02:20:58 by adelille          #+#    #+#             */
/*   Updated: 2021/04/01 15:59:50 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_sort_3(t_arg *arg)
{
	if (arg->a->data == ft_biggest(arg->a))
	{
		if (ft_lst_last(arg->a) == ft_smallest(arg->a))
			return (ft_ps("sa\nrra\n"));
		return (ft_ps("ra\n"));
	}
	else if (arg->a->data != ft_smallest(arg->a))
	{
		if (ft_lst_last(arg->a) == ft_smallest(arg->a))
			return (ft_ps("rra\n"));
		return (ft_ps("sa\n"));
	}
	return (ft_ps("rra\nsa\n"));
}

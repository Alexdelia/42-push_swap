/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 15:27:35 by adelille          #+#    #+#             */
/*   Updated: 2021/03/24 03:21:50 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_op_sa(t_arg *arg)
{
	int	tmp;

	if (!arg->a || !arg->a->next)
		return (0);
	tmp = arg->a->data;
	arg->a->data = arg->a->next->data;
	arg->a->next->data = tmp;
	return (0);
}

int	ft_op_sb(t_arg *arg)
{
	int	tmp;

	if (!arg->b || !arg->b->next)
		return (0);
	tmp = arg->b->data;
	arg->b->data = arg->b->next->data;
	arg->b->next->data = tmp;
	return (0);
}

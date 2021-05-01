/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mt_min.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 14:53:49 by adelille          #+#    #+#             */
/*   Updated: 2021/05/01 14:58:24 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int		ft_mt_min(t_mt *mt)
{
	int	min;

	min = INT_MAX;
	while (mt)
	{
		if (mt->nb < min)
			min = mt->nb;
		mt = mt->next;
	}
	return (min);
}

int		ft_mt_nextmin(t_mt *mt, int over)
{
	int	min;

	min = INT_MAX;
	while (mt)
	{
		if (mt->nb < min && mt->nb > over)
			min = mt->nb;
		mt = mt->next;
	}
	return (min);
}

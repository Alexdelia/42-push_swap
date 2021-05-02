/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 14:59:03 by adelille          #+#    #+#             */
/*   Updated: 2021/05/02 14:21:28 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int		ft_fill_index(t_mt **mt, int nb, int index)
{
	while (*mt)
	{
		if ((*mt)->nb == nb)
		{
			(*mt)->index = index;
			return (TRUE);
		}
		*mt = (*mt)->next;
	}
	return (FALSE);
}

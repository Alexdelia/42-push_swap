/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_duplicate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:54:25 by adelille          #+#    #+#             */
/*   Updated: 2021/07/21 22:54:52 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_check_duplicate(t_markup	*ma)
{
	int		i;
	t_mt	*x;
	t_mt	*y;

	i = 0;
	x = ma->head;
	while (i < ma->size)
	{
		y = x->next;
		while (y != x)
		{
			if (x->nb == y->nb)
				ft_exit("Error: One int is present multiple times\n");
			y = y->next;
		}
		x = x->next;
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:57:28 by adelille          #+#    #+#             */
/*   Updated: 2021/10/05 19:02:56 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void	ft_double_rotator(t_data *d, int *ra, int *rb)
{
	while (*ra > 0 && *rb > 0)
	{
		(*ra)--;
		(*rb)--;
		ft_rr(d);
	}
	while (*ra < 0 && *rb < 0)
	{
		(*ra)++;
		(*rb)++;
		ft_rrr(d);
	}
}

void	ft_rotator(t_data *d, int ra, int rb)
{
	ft_double_rotator(d, &ra, &rb);
	while (ra > 0)
	{
		ra--;
		ft_ra(d);
	}
	while (ra < 0)
	{
		ra++;
		ft_rra(d);
	}
	while (rb > 0)
	{
		rb--;
		ft_rb(d);
	}
	while (rb < 0)
	{
		rb++;
		ft_rrb(d);
	}
}

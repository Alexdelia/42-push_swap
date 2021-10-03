/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 22:06:54 by adelille          #+#    #+#             */
/*   Updated: 2021/10/03 22:11:07 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_stacklen(t_stack *s)
{
	int	i;

	i = 0;
	while (s)
	{
		i++;
		s = s->next;
	}
	return (i);
}

int	ft_distance_to_top(t_stack *a, int index)
{
	int	i;
	int	size;

	i = 0;
	while (a)
	{
		if (a->index == index)
			break ;
		a = a->next;
		i++;
	}
	size = ft_stacklen(a);
	if (i > size / 2)
		i -= size;
	return (i);
}

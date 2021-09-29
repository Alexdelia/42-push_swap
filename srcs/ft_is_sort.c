/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:02:44 by adelille          #+#    #+#             */
/*   Updated: 2021/09/29 16:05:09 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_is_sort(t_data *d)
{
	int		prev;
	t_stack	*s;

	if (d->b)
		return (FALSE);
	if (!d->a)
		return (TRUE);
	s = d->a;
	prev = s->data;
	while (s)
	{
		if (prev > s->data)
			return (FALSE);
		prev = s->data;
		s = s->next;
	}
	return (TRUE);
}

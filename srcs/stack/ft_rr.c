/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:34:09 by adelille          #+#    #+#             */
/*   Updated: 2021/09/30 18:59:06 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void	ft_rru(t_stack **s)
{
	t_stack	*last;
	t_stack	*prev;

	if (!*s || !(*s)->next)
		return ;
	last = *s;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	last->next = (*s);
	*s = last;
	prev->next = NULL;
}

void	ft_rra(t_data *d)
{
	ft_rru(&(d->a));
	if (d->print)
		ft_ps("rra\n");
}

void	ft_rrb(t_data *d)
{
	ft_rru(&(d->b));
	if (d->print)
		ft_ps("rrb\n");
}

void	ft_rrr(t_data *d)
{
	ft_rru(&(d->a));
	ft_rru(&(d->b));
	if (d->print)
		ft_ps("rrr\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:13:45 by adelille          #+#    #+#             */
/*   Updated: 2021/09/30 18:56:07 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void	ft_s(t_stack **s)
{
	t_stack	*tmp;
	t_stack	*third;

	if (!*s || !(*s)->next)
		return ;
	third = (*s)->next->next;
	tmp = *s;
	*s = (*s)->next;
	(*s)->next = tmp;
	tmp->next = third;
}

void	ft_sa(t_data *d)
{
	ft_s(&(d->a));
	if (d->print)
		ft_ps("sa\n");
}

void	ft_sb(t_data *d)
{
	ft_s(&(d->b));
	if (d->print)
		ft_ps("sb\n");
}

void	ft_ss(t_data *d)
{
	ft_s(&(d->a));
	ft_s(&(d->b));
	if (d->print)
		ft_ps("ss\n");
}

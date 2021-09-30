/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:29:35 by adelille          #+#    #+#             */
/*   Updated: 2021/09/30 18:55:57 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void	ft_ru(t_stack **s)
{
	t_stack	*head;
	t_stack	*tmp;

	if (!*s || !(*s)->next)
		return ;
	head = *s;
	*s = (*s)->next;
	tmp = *s;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = head;
	head->next = NULL;
}

void	ft_ra(t_data *d)
{
	ft_ru(&(d->a));
	if (d->print)
		ft_ps("ra\n");
}

void	ft_rb(t_data *d)
{
	ft_ru(&(d->b));
	if (d->print)
		ft_ps("rb\n");
}

void	ft_rr(t_data *d)
{
	ft_ru(&(d->a));
	ft_ru(&(d->b));
	if (d->print)
		ft_ps("rr\n");
}

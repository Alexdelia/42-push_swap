/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:17:27 by adelille          #+#    #+#             */
/*   Updated: 2021/10/08 11:17:05 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void	ft_p(t_stack **s1, t_stack **s2)
{
	t_stack	*head;

	if (!*s1)
		return ;
	head = *s1;
	*s1 = head->next;
	if (*s2)
		head->next = (*s2);
	else
		head->next = NULL;
	*s2 = head;
}

void	ft_pa(t_data *d)
{
	ft_p(&(d->b), &(d->a));
	if (d->print)
		ft_ps("pa\n");
}

void	ft_pb(t_data *d)
{
	ft_p(&(d->a), &(d->b));
	if (d->print)
		ft_ps("pb\n");
}

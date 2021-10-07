/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:08:40 by adelille          #+#    #+#             */
/*   Updated: 2021/10/07 18:05:42 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int	ft_in_stack(t_stack *s, int data)
{
	while (s)
	{
		if (s->data == data)
			return (TRUE);
		s = s->next;
	}
	return (0);
}

int	ft_push_init(t_stack **s, int data, int index)
{
	t_stack	*elem;
	t_stack	*last;

	last = *s;
	if (ft_in_stack(*s, data) == TRUE)
		return (ft_pserc("Error: One int is present multiples times\n",
				RED) * 0);
	elem = malloc(sizeof(t_stack));
	if (!elem)
		return (ft_pser("Malloc error in ft_push_init\n") * 0);
	elem->data = data;
	elem->index = index;
	elem->next = NULL;
	elem->next_sort = NULL;
	if (last == NULL)
	{
		*s = elem;
		return (TRUE);
	}
	while (last->next)
		last = last->next;
	last->next = elem;
	last->next_sort = elem;
	return (TRUE);
}

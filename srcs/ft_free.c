/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:45:55 by adelille          #+#    #+#             */
/*   Updated: 2021/09/28 15:50:14 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_free_stack(t_stack **stack)
{
	t_stack	*s;
	t_stack	*next;

	s = *stack;
	while (s)
	{
		next = s->next;
		free(s);
		s = next;
	}
	*stack = NULL;
	return (1);
}

int	ft_free_data(t_data *d)
{
	ft_free_stack(&(d->a));
	ft_free_stack(&(d->b));
	return (1);
}

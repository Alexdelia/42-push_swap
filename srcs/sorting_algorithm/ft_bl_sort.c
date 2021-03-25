/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bl_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 20:22:24 by adelille          #+#    #+#             */
/*   Updated: 2021/03/25 20:42:49 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

// find smallest
// rotate or reverse rotate (count commands) [if v, draw command]
// push to b (n_command + 1) [if v, draw command]
// redo until ft_lstsize(b) == ft_lstsize(a initial) - 1 [if v, draw command]
// push to a until ft_lstsize(a) == ft_lstsize(a initial) (count commands) [if v, draw command]
// return n_command

int	ft_bl_sort(t_arg arg, int v)
{
	int	smallest;
	int	value;
	int	i;
	int	sorted;
	int	n_command;
	t_list	*head;

	smallest = -1;
	value = INT_MAX;
	i = 1;
	head = arg->a;
	sorted = FALSE;
	n_command = 0;
	while (sorted == TRUE)
	{
		if (arg->a->data < value)
		{
			value = arg->a->data;
			smallest = i;
		}
		i++;
		
		arg->a = arg->a->next;
	}
}

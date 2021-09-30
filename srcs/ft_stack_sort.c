/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:10:04 by adelille          #+#    #+#             */
/*   Updated: 2021/09/30 18:16:14 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_stack_sort(t_stack **head)
{
	t_stack	*last;
	t_stack	*prev;

	prev = NULL;
	last = *head;
	while (last && last->next_sort)
	{
		if (last->data - last->next_sort->data > 0)
		{
			if (perv == NULL)
				ft_s(head, last);
			else
				ft_s(&(prev->next_sort), last);
			last = *head;
			prev = NULL;
		}
		else
		{
			prev = last;
			last = last->next_sort;
		}
	}
}

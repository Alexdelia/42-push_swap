/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_markup_option.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 15:12:34 by adelille          #+#    #+#             */
/*   Updated: 2021/07/21 22:47:01 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_markup_index(t_markup *ma, t_mt *head)
{
	int		index;
	int		pairs;
	t_mt	*current;

	pairs = 0;
	if (ma && head)
	{
		index = head->index;
		head->keep = TRUE;
		current = head->next;
		while (current != head)
		{
			if (current->index == index + 1)
			{
				pairs++;
				index++;
				current->keep = TRUE;
			}
			else
				current->keep = FALSE;
			current = current->next;
		}
	}
	return (pairs);
}

int	ft_markup_gt(t_markup *ma, t_mt *head)
{
	int		index;
	int		pairs;
	t_mt	*current;

	pairs = 0;
	if (ma && head)
	{
		index = head->index;
		head->keep = TRUE;
		current = head->next;
		while (current != head)
		{
			if (current->index > index)
			{
				pairs++;
				index = current->index;
				current->keep = TRUE;
			}
			else
				current->keep = FALSE;
			current = current->next;
		}
	}
	return (pairs);
}

void	ft_markup_option(t_markup *ma, int (*ft_markup_s)(t_markup *, t_mt *))
{
	int		i;
	int		pairs;
	t_mt	*current;

	if (ma)
	{
		i = 0;
		current = ma->head;
		while (i < ma->size)
		{
			pairs = ft_markup_s(ma, current);
			if (pairs > ma->pairs)
			{
				ma->head = current;
				ma->pairs = pairs;
			}
			else if (pairs == ma->pairs
					&& (!ma->head || current->nb < ma->head->nb))
				ma->head = current;
			i++;
			current = current->next;
		}
	}
	ft_markup_s(ma, ma->head);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 20:43:01 by adelille          #+#    #+#             */
/*   Updated: 2021/07/15 20:48:26 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_push(t_markup *ma, t_mt *mt)
{
	t_mt	*tail;

	if (ma && mt)
	{
		if (!ma->head)
		{
			ma->head = mt;
			ma->head->prev = ma->head;
			ma->head->next = ma->head;
		}
		else
		{
			tail = ma->head->prev;
			mt->prev = tail;
			tail->next = mt;
			mt->next = ma->head;
			ma->head->prev = mt;
			ma->head = mt;
		}
		ma->size++;
	}
}

t_mt	*ft_pop(t_markup *ma)
{
	t_mt	*mt;

	mt = NULL;
	if (ma && ma->size)
	{
		if (ma->sie == 1)
		{
			mt = ma->head;
			ma->head = NULL;
		}
		else
		{
			mt = ma->head;
			ma->head = ma->head->next;
			mt->prev->next = mt->next;
			mt->next->prev = mt->prev;
		}
		mt->prev = NULL;
		mt->next = NULL;
		stack->size--;
	}
	return (mt);
}

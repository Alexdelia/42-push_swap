/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mt_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:53:36 by adelille          #+#    #+#             */
/*   Updated: 2021/07/08 17:57:52 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_mt_add(t_markup *ma, t_mt *new)
{
	t_mt	*tail;

	if (ma && new)
	{
		if (!ma->head)
		{
			ma->head = new;
			ma->head->prev = ma->head;
			ma->head->next = ma->head;
		}
		else
		{
			tail = ma->head->prev;
			new->prev = tail;
			tail->next = new;
			new->next = ma->head;
			ma->head->prev = new;
		}
		ma->size++;
	}
}

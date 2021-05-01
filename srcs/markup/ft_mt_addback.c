/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mt_addback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 14:49:57 by adelille          #+#    #+#             */
/*   Updated: 2021/05/01 14:51:52 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_mt_addback(t_mt **alst, t_mt *new)
{
	t_mt	*last;

	if (alst)
	{
		if (*alst)
		{
			last = ft_mt_last(*alst);
			last->next = new;
		}
		else
			*alst = new;
	}
}

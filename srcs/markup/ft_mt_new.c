/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mt_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 14:46:07 by adelille          #+#    #+#             */
/*   Updated: 2021/07/08 18:01:25 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_mt	*ft_mt_new(int nb)
{
	t_mt	*new;
	new = (t_mt *)ft_memalloc(sizeof(t_mt));
	if (!new)
		ft_exit("Error: Malloc failed in ft_mt_new\n");
	new->nb = nb;
	new->index = -1;
	new->keep = false;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

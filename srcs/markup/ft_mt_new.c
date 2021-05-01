/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mt_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 14:46:07 by adelille          #+#    #+#             */
/*   Updated: 2021/05/01 14:48:32 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_mt	*ft_mt_new(int nb, int index, int keep)
{
	t_mt	*elt;

	elt = (t_mt *)malloc(sizeof(*elt));
	if (!elt)
		return (NULL);
	elt->nb = nb;
	elt->index = index;
	elt->keep = keep;
	elt->next = NULL;
	return (elt);
}

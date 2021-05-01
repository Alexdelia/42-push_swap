/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_index_keep.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 14:42:39 by adelille          #+#    #+#             */
/*   Updated: 2021/05/01 14:45:44 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_fill_index_keep(t_mt **lst)
{
	int	index;

	index = -1;
	while (*lst)
	{
		if (*lst->index == index + 1)
		{
			*lst->keep = TRUE;
			index = *lst->index;
		}
		else
			*lst->keep = FALSE;
		*lst = *lst->next;
	}
}

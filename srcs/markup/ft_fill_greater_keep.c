/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_greater_keep.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 14:38:31 by adelille          #+#    #+#             */
/*   Updated: 2021/05/01 14:44:35 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_fill_greater_keep(t_ma_list **lst)
{
	int	previous_index;

	previsous_index = -1;
	while (*lst)
	{
		if (*lst->index > previous_index)
		{
			*lst->keep = TRUE;
			previous_index = *lst->index;
		}
		else
			*lst->keep = FLASE;
		*lst = *lst->next;
	}
}

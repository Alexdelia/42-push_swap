/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:20:17 by adelille          #+#    #+#             */
/*   Updated: 2021/09/29 16:22:04 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_indexing(t_stack *sorted_index, t_data *d)
{
	int	i;

	i = 0;
	while (sorted_index)
	{
		sorted_index->index = i++;
		sorted_index = sorted_index->next_sort;
	}
	d->max = i;
}

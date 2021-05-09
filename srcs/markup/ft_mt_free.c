/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mt_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:44:27 by adelille          #+#    #+#             */
/*   Updated: 2021/05/09 14:02:24 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_mt_free(t_mt *mt)
{
	if (mt)
		free(mt);
}

void	ft_mt_freeall(t_mt **mt)
{
	t_mt	*mt;

	if (!mt || !*mt)
		return ;
	while (*mt)
	{
		tmp = (*mt)->next;
		ft_mt_free(*mt);
		*mt = tmp;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mt_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 22:46:36 by adelille          #+#    #+#             */
/*   Updated: 2021/06/23 16:30:59 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

/*void	ft_mt_p(t_markup *mt, int type)
{
	t_mt	*tmp;

	if (type == MT_A)
	{
		tmp = mt->a;
		mt->a = mt->b;
		mt->a->next = tmp;
		mt->b = mt->b->next;
	}
	else if (type == MT_B)
	{
		tmp = mt->b;
		mt->b = mt->a;
		mt->b->next = tmp;
		mt->a = mt->a->next;
	}
}*/

void	ft_mt_p(t_mt **dst, t_mt **src)
{
	t_mt	*tmp;

	if (src == NULL || (*src) == NULL)
		return ;
	tmp = *src;
	ft_mt_addfront(dst, ft_mt_new(tmp->nb, tmp->index, tmp->keep));
	*(src) = (*src)->next;
	ft_mt_free(tmp);
}

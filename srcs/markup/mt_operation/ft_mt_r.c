/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mt_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 22:50:14 by adelille          #+#    #+#             */
/*   Updated: 2021/06/15 18:21:14 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_mt_r(t_markup *mt, int type)
{
	t_mt	*tmp;

	if (type == MT_A)
	{
		tmp = mt->a;
		mt->a = mt->a->next;
		ft_mt_addback(&mt->a, ft_mt_new(tmp->nb, tmp->index, tmp->keep));
	}	
	else if (type == MT_B)
	{
		tmp = mt->b;
		mt->b = mt->b->next;
		ft_mt_addback(&mt->b, ft_mt_new(tmp->nb, tmp->index, tmp->keep));
	}
	else
	{
		ft_pser("Wrong type in ra-rb");
		tmp = mt->a;
	}
	ft_mt_free(tmp);
}

void	ft_mt_rr(t_markup *mt, int type)
{
	t_mt	*f;
	t_mt	*tmp;

	if (type == MT_A)
		f = mt->a;
	else if (type == MT_B)
		f = mt->a;
	else
	{
		ft_pser("Wrong type in rra-rrb");
		return ;
	}
	tmp = NULL;
	while (f->next)
	{
		tmp = f;
		f = f->next;
	}
	if (type == MT_A)
		ft_mt_addfront(&mt->a, ft_mt_new(f->nb, f->index, f->keep));
	else if (type == MT_B)
		ft_mt_addfront(&mt->b, ft_mt_new(f->nb, f->index, f->keep));
	tmp->next = NULL;
	ft_mt_free(f);
}

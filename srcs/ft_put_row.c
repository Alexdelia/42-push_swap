/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_row.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 04:06:26 by adelille          #+#    #+#             */
/*   Updated: 2021/03/24 04:21:06 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_put_row(t_arg arg, int ga, int gb, int i)
{
	ft_ps("\t");
	if (arg.a)
	{
		if (ga == i && arg.c == 1)
			ft_psc(ft_itoa(arg.a->data), GRN);
		else
			ft_ps(ft_itoa(arg.a->data));
	}
	else
		ft_ps("   ");
	ft_ps("\t");
	if (arg.b)
	{
		if (gb == i && arg.c == 1)
			ft_psc(ft_itoa(arg.b->data), GRN);
		else
			ft_ps(ft_itoa(arg.b->data));
	}
	ft_ps("\n");
}

void	ft_put_row_sa(t_arg arg, int i)
{
	ft_ps("\t");
	if (arg.a)
	{
		if ((i == 1 || i == 2) && arg.c == 1)
			ft_psc(ft_itoa(arg.a->data), GRN);
		else
			ft_ps(ft_itoa(arg.a->data));
	}
	else
		ft_ps("  ");
	ft_ps("\t");
	if (arg.b)
		ft_ps(ft_itoa(arg.b->data));
	ft_ps("\n");
}

void	ft_put_row_sb(t_arg arg, int i)
{
	ft_ps("\t");
	if (arg.a)
		ft_ps(ft_itoa(arg.a->data));
	else
		ft_ps("  ");
	ft_ps("\t");
	if (arg.b)
	{
		if ((i == 1 || i == 2) && arg.c == 1)
			ft_psc(ft_itoa(arg.b->data), GRN);
		else
			ft_ps(ft_itoa(arg.b->data));
	}
	ft_ps("\n");
}

void	ft_put_row_ss(t_arg arg, int i)
{
	ft_ps("\t");
	if (arg.a)
	{
		if ((i == 1 || i == 2) && arg.c == 1)
			ft_psc(ft_itoa(arg.a->data), GRN);
		else
			ft_ps(ft_itoa(arg.a->data));
	}
	else
		ft_ps("  ");
	ft_ps("\t");
	if (arg.b)
	{
		if ((i == 1 || i == 2) && arg.c == 1)
			ft_psc(ft_itoa(arg.b->data), GRN);
		else
			ft_ps(ft_itoa(arg.b->data));
	}
	ft_ps("\n");
}

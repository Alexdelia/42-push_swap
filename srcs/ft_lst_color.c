/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:29:46 by adelille          #+#    #+#             */
/*   Updated: 2021/03/24 03:49:37 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_lst_color(t_arg arg, int ga, int gb)
{
	int	i;

	if (arg.v == 0)
		return (0);
	ft_psc("~\t a \t b \t~\n", "\033[1;29m");
	ft_ps("\t---\t---\n");
	i = 0;
	while ((arg.a || arg.b) && ++i >= 0)
	{
		ft_ps("\t");
		if (ga == i && arg.c == 1)
			ft_psc(ft_itoa(arg.a->data), GRN);
		else
			ft_ps(ft_itoa(arg.a->data));
		ft_ps("\t");
		if (gb == i && arg.c == 1)
			ft_psc(ft_itoa(arg.b->data), GRN);
		else
			ft_ps(ft_itoa(arg.b->data));
		ft_ps("\n");
		arg.a = arg.a->next;
		arg.b = arg.b->next;
	}
	ft_ps("\t---\t---\n\n");
	return (0);
}

int	ft_lst_color_sa(t_arg arg)
{
	int	i;

	if (arg.v == 0)
		return (0);
	ft_psc("~\t a \t b \t~\n", "\033[1;29m");
	ft_ps("\t---\t---\n");
	i = 1;
	while (arg.a || arg.b)
	{
		ft_ps("\t");
		if ((i == 1 || i == 2) && arg.c == 1)
			ft_psc(ft_itoa(arg.a->data), GRN);
		else
			ft_ps(ft_itoa(arg.a->data));
		ft_ps("\t");
		ft_ps(ft_itoa(arg.b->data));
		ft_ps("\n");
		if (arg.a)
			arg.a = arg.a->next;
		if (arg.b)
			arg.b = arg.b->next;
		i++;
	}
	ft_ps("\t---\t---\n\n");
	return (0);
}

int	ft_lst_color_sb(t_arg arg)
{
	int	i;

	if (arg.v == 0)
		return (0);
	ft_psc("~\t a \t b \t~\n", "\033[1;29m");
	ft_ps("\t---\t---\n");
	i = 1;
	while (arg.a || arg.b)
	{
		ft_ps("\t");
		ft_ps(ft_itoa(arg.a->data));
		ft_ps("\t");
		if ((i == 1 || i == 2 ) && arg.c == 1)
			ft_psc(ft_itoa(arg.b->data), GRN);
		else
			ft_ps(ft_itoa(arg.b->data));
		ft_ps("\n");
		if (arg.a)
			arg.a = arg.a->next;
		if (arg.b)
			arg.b = arg.b->next;
		i++;
	}
	ft_ps("\t---\t---\n\n");
	return (0);
}

int	ft_lst_color_ss(t_arg arg)
{
	int	i;

	if (arg.v == 0)
		return (0);
	ft_psc("~\t a \t b \t~\n", "\033[1;29m");
	ft_ps("\t---\t---\n");
	i = 0;
	while ((arg.a || arg.b) && ++i >= 0)
	{
		ft_ps("\t");
		if ((i == 1 || i == 2) && arg.c == 1)
			ft_psc(ft_itoa(arg.a->data), GRN);
		else
			ft_ps(ft_itoa(arg.a->data));
		ft_ps("\t");
		if ((i == 1 || i == 2) && arg.c == 1)
			ft_psc(ft_itoa(arg.b->data), GRN);
		else
			ft_ps(ft_itoa(arg.b->data));
		ft_ps("\n");
		arg.a = arg.a->next;
		arg.b = arg.b->next;
	}
	ft_ps("\t---\t---\n\n");
	return (0);
}

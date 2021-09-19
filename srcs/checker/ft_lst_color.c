/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:29:46 by adelille          #+#    #+#             */
/*   Updated: 2021/03/24 04:23:28 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_lst_color(t_arg arg, int ga, int gb)
{
	int	i;

	if (arg.v == 0)
		return (0);
	ft_psc(" ~\t a \t b \t~\n", "\033[1;29m");
	ft_ps("\t---\t---\n");
	i = 1;
	while (arg.a || arg.b)
	{
		ft_put_row(arg, ga, gb, i);
		if (arg.a)
			arg.a = arg.a->next;
		if (arg.b)
			arg.b = arg.b->next;
		i++;
	}
	ft_ps("\t---\t---\n\n");
	return (0);
}

int	ft_lst_color_sa(t_arg arg)
{
	int	i;

	if (arg.v == 0)
		return (0);
	ft_psc(" ~\t a \t b \t~\n", "\033[1;29m");
	ft_ps("\t---\t---\n");
	i = 1;
	while (arg.a || arg.b)
	{
		ft_put_row_sa(arg, i);
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
	ft_psc(" ~\t a \t b \t~\n", "\033[1;29m");
	ft_ps("\t---\t---\n");
	i = 1;
	while (arg.a || arg.b)
	{
		ft_put_row_sb(arg, i);
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
	ft_psc(" ~\t a \t b \t~\n", "\033[1;29m");
	ft_ps("\t---\t---\n");
	i = 1;
	while (arg.a || arg.b)
	{
		ft_put_row_ss(arg, i);
		if (arg.a)
			arg.a = arg.a->next;
		if (arg.b)
			arg.b = arg.b->next;
		i++;
	}
	ft_ps("\t---\t---\n\n");
	return (0);
}

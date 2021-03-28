/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opti_top_bot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 02:02:23 by adelille          #+#    #+#             */
/*   Updated: 2021/03/28 09:57:22 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_opti_shared_r(t_list **lst, int v, char *type)
{
	ft_op_r(lst);
	if (v == TRUE)
	{
		ft_ps("r");
		ft_ps(type);
	}
	return (1);
}

int	ft_opti_shared_rr(t_list **lst, int v, char *type)
{
	ft_op_rr(lst);
	if (v == TRUE)
	{
		ft_ps("rr");
		ft_ps(type);
	}
	return (1);
}

int	ft_opti_top(t_list **lst, int data, int v, char *type)
{
	int	n_command;

	n_command = 0;
	if (ft_find_close(*lst, data) == -1)
	{
		while ((*lst)->data != data)
			n_command += ft_opti_shared_r(lst, v, type);
		return (n_command);
	}
	while ((*lst)->data != data)
		n_command += ft_opti_shared_rr(lst, v, type);
	return (n_command);
}

int	ft_opti_bot(t_list **lst, int data, int v, char *type)
{
	int	n_command;

	n_command = 0;
	if (ft_find_close(*lst, data) == 1)
	{
		while (ft_lst_last(*lst) != data)
			n_command += ft_opti_shared_r(lst, v, type);
		return (n_command);
	}
	while (ft_lst_last(*lst) != data)
		n_command += ft_opti_shared_rr(lst, v, type);
	return (n_command);
}

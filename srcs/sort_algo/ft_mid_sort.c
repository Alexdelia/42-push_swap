/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mid_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 07:48:45 by adelille          #+#    #+#             */
/*   Updated: 2021/03/29 16:01:15 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_clean_a_at_start(t_arg *arg, int v)
{	
	if (arg->a->data > arg->a->next->data)
	{
		ft_op_sa(arg);
		if (v == TRUE)
			ft_ps("sa\n");
		return (1);
	}
	return (0);
}

int	ft_lst_x(t_list *lst, int x)
{
	while (x > 0 && lst->next)
	{
		lst = lst->next;
		x--;
	}
	return (lst->data);
}

int	ft_put_b_back(t_arg *arg, int i)
{
	int	n_command;

	i--;
	n_command = 0;
	while (i >= 0 && arg->b)
	{
		if (ft_check_unsort(arg->b) == TRUE)
		{
			n_command += ft_last_chunk(arg, ft_lstsize(arg->b));
			i = -1;
		}
		else if (ft_lst_x(arg->chunk, i) == 1 || ft_lst_x(arg->chunk, i) == 2)
			n_command += ft_first_chunk(arg, ft_lst_x(arg->chunk, i));
		else if (i == 0)
			n_command += ft_last_chunk(arg, ft_lst_x(arg->chunk, i));
		else
			n_command += ft_mid_chunk(arg, ft_lst_x(arg->chunk, i));
		i--;
	}
	ft_lstclear(&arg->chunk);
	return (n_command);
}

int	ft_mid_sort(t_arg *arg)
{
	int	n_command;
	int	i;

	n_command = 0;
	i = 0;
	while (ft_lstsize(arg->a) > 2)
	{
		n_command += ft_advance_separate(arg);
		i++;
	}
	n_command += ft_clean_a_at_start(arg, TRUE);
	n_command += ft_put_b_back(arg, i);
	return (n_command);
}

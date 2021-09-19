/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mt_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 22:50:14 by adelille          #+#    #+#             */
/*   Updated: 2021/07/21 22:43:07 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_mt_rx(t_markup *ma, char *name, t_arg_list *arg_list)
{
	if (ma && ma->head)
		ma->head = ma->head->next;
	if (name && !arg_list)
		ft_ps(name);
	if (name && arg_list)
		ft_add_command(arg_list, ft_create_command(name)); // to code
}

void	ft_mt_rr(t_markup *a, t_markup *b,
		char *name, t_arg_list *arg_list)
{
	ft_mt_rx(a, NULL, NULL);
	ft_mt_rx(b, NULL, NULL);
	if (name && !arg_list)
		ft_ps(name);
	if (name && arg_list)
		ft_add_command(arg_list, ft_create_command(name));
}

void	ft_mt_rrx(t_markup *ma, char *name, t_arg_list *arg_list)
{
	if (ma && ma->head)
		ma->head = ma->head->prev;
	if (name && !arg_list)
		ft_ps(name);
	if (name && arg_list)
		ft_add_command(arg_list, ft_create_command(name)); // to code
}

void	ft_mt_rrr(t_markup *a, t_markup *b,
		char *name, t_arg_list *arg_list)
{
	ft_mt_rrx(a, NULL, NULL);
	ft_mt_rrx(b, NULL, NULL);
	if (name && !arg_list)
		ft_ps(name);
	if (name && arg_list)
		ft_add_command(arg_list, ft_create_command(name));
}

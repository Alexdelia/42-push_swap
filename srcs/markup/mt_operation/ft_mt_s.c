/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mt_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 22:35:37 by adelille          #+#    #+#             */
/*   Updated: 2021/07/21 22:45:09 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void	ft_swap(t_mt *s1, t_mt *s2, t_markup *ma)
{
	t_mt	*prev;
	t_mt	*next;

	prev = s1->prev;
	next = s2->next;
	prev->next = s2;
	s2->prev = prev;
	s1->next = next;
	next->prev = s1;
	s2->next = s1;
	s1->prev = s2;
	ma->head = s2;
}

void	ft_mt_sx(t_markup *ma,char *name, t_arg_list *arg_list)
{
	if (ma && ma->head && ma->size >= 2)
		ft_swap(ma->head, ma->head->next, ma);
	if (name && !arg_list)
		ft_ps(name);
	if (name && arg_list)
		ft_add_command(arg_list, ft_create_command(name));
}

void	ft_mt_ss(t_markup *a, t_markup *b,
		char *name, t_arg_list *arg_list)
{
	ft_mt_sx(a, NULL, NULL);
	ft_mt_sx(b, NULL, NULL);
	if (name && !arg_list)
		ft_ps(name);
	if (name && arg_list)
		ft_add_command(arg_list, ft_create_command(name));
}

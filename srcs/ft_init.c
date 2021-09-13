/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 15:23:07 by adelille          #+#    #+#             */
/*   Updated: 2021/09/13 18:51:37 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_arg_list	*ft_init_arg_list(void)
{
	t_arg_list	*arg_list;

	arg_list = (t_arg_list *)ft_memalloc(sizeof(t_arg_list));
	if (!arg_list)
		ft_exit("Error: Malloc failed in ft_init_arg_list\n");
	arg_list->size = 0;
	arg_list->head = NULL;
	return (arg_list);
}

t_markup	*ft_init_stack(void)
{
	t_markup	*ma;

	ma = (t_markup *)ft_memalloc(sizeof(t_markup));
	if (!ma)
		ft_exit("Error: Malloc failed in ft_init_stack\n");
	ma->size = 0;
	ma->pairs = 0;
	ma->head = NULL;
	ma->markup_head = NULL;
	return (ma);
}

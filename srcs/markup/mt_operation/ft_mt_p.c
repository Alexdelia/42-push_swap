/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mt_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 22:46:36 by adelille          #+#    #+#             */
/*   Updated: 2021/07/15 20:42:48 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_mt_p(t_markup *dst, t_markup *src,
		const char *name, t_arg_list *arg_list)
{
	ft_push(dst, ft_pop(src));
	if (name && !arg_list)
		ft_ps(name);
	if (name && arg_list)
		ft_add_command(arg_list, ft_create_command(name)); // to code
}

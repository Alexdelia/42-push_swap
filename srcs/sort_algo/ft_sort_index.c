/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 14:14:56 by adelille          #+#    #+#             */
/*   Updated: 2021/05/20 22:45:32 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_sort_index(t_arg *arg, int print)
{
	t_markup	in;

	ft_init_markup(&in, arg, 2);
	return (ft_sort_markup(&in, 2, print));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_greater.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 13:44:26 by adelille          #+#    #+#             */
/*   Updated: 2021/05/01 13:55:00 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int		ft_sort_greater(t_arg *arg, int print)
{
	t_markup	gr;

	ft_init_markup(&gr, arg, 1);
	return (ft_sort_markup(&gr, print));
}

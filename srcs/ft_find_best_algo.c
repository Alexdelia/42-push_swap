/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_best_algo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 00:21:06 by adelille          #+#    #+#             */
/*   Updated: 2021/03/27 02:54:33 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_find_best_algo(t_arg *arg)
{
	if (ft_check_sort(arg->a) == TRUE)
		return (0);
	if (ft_lstsize(arg->a) == 3)
		return (ft_sort_3(*arg));
	return (ft_alex_sort(*arg, TRUE));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_best_algo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 00:21:06 by adelille          #+#    #+#             */
/*   Updated: 2021/05/01 13:45:21 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_find_best_algo(t_arg *arg)
{
	if (ft_check_sort(arg->a) == TRUE)
		return (0);
	if (ft_lstsize(arg->a) == 3)
		return (ft_sort_3(arg));
	if (ft_sort_greater(arg, FALSE) < ft_sort_index(arg, FALSE))
		return (ft_sort_greater(arg, TRUE));
	else
		return (ft_sort_index(arg, TRUE));
	//return (ft_mid_sort(arg));
}

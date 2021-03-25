/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 20:04:48 by adelille          #+#    #+#             */
/*   Updated: 2021/03/25 20:25:42 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_find_sort(t_arg *arg)
{
	int	n_command;

	if (arg->aas == TRUE)
		n_command = ft_alex_advance_sort(arg, TRUE);
	if (arg->ins == TRUE)
		n_command = ft_insertion_sort(arg, TRUE);
	else
		n_command = ft_best_sort(arg);
	return (n_command);
}

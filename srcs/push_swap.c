/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 19:05:39 by adelille          #+#    #+#             */
/*   Updated: 2021/07/20 15:23:29 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	main(int ac, char **av)
{
	t_markup	*ma_index;
	t_markup	*ma_gt;
	t_arg_list	*arg_index;
	t_arg_list	*arg_gt;

	if (ac < 2)
		return (ft_pser("Error: Not enough argument\n") * 0 + 1);
	ft_check_duplicate((ma_index = ft_parse(ac, av)));
	ft_index(ma_index);
	ft_markup_option(ma_index, &ft_markup_index);
	arg_index = ft_solve(ma_index, &ft_markup_index);
	ft_free_stack(ma_index);
	ft_index(ma_gt = ft_parse(ac, av));
	ft_markup_option(ma_gt, &ft_markup_gt);
	arg_gt = ft_solve(ma_gt, &ft_markup_gt);
	ft_free_stack(ma_gt);
	if (arg_index->size < arg_gt->size)
		ft_prints_commands(arg_index);
	else
		ft_prints_commands(arg_gt);
	ft_free_arg_list(arg_index);
	ft_free_arg_list(arg_gt);
	return (0);
}

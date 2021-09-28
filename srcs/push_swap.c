/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 19:05:39 by adelille          #+#    #+#             */
/*   Updated: 2021/09/28 15:03:24 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	main(int ac, char **av)
{
	t_data	d;

	d.a = NULL;
	d.b = NULL;
	if (ac < 2)
		return (ft_pserc("Error: Not enough argument\n", RED) * 0 + 1);
	if (ft_arg(ac, av, &d) == FALSE)
		return (1);
	//ft_check_duplicate((ma_index = ft_parse(ac, av)));
	ft_index(ma_index);
	ft_markup_option(ma_index, &ft_markup_index);
	arg_index = ft_solve(ma_index, &ft_markup_index);
	ft_free_stack(ma_index);
	ft_index(ma_gt = ft_parse(ac, av));
	ft_markup_option(ma_gt, &ft_markup_gt);
	arg_gt = ft_solve(ma_gt, &ft_markup_gt);
	ft_free_stack(ma_gt);
	if (arg_index->size < arg_gt->size)
		ft_print_commands(arg_index);
	else
		ft_print_commands(arg_gt);
	ft_free_arg_list(arg_index);
	ft_free_arg_list(arg_gt);
	return (0);
}

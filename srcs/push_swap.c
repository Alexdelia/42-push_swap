/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 19:05:39 by adelille          #+#    #+#             */
/*   Updated: 2021/07/06 15:51:30 by adelille         ###   ########.fr       */
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

	v = ft_visual(av);
	if (v == TRUE)
		ft_psc("\nParsing ...\t", "\033[1;29m");
	ft_arg(&arg, ac, av);
	if (arg.err == TRUE)
		return (0);
	if (v == TRUE)
	{
		ft_psc("Done\n", GRN);
		ft_psc("Sorting ...\n", "\033[1;29m");
	}
	ft_find_best_algo(&arg);
	ft_lstclear(&arg.a);
	if (arg.b)
		ft_lstclear(&arg.b);
}

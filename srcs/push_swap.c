/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 19:05:39 by adelille          #+#    #+#             */
/*   Updated: 2021/10/09 19:34:59 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	main(int ac, char **av)
{
	t_data	d;
	t_stack	*sorted_index;

	d.a = NULL;
	d.b = NULL;
	d.print = TRUE;
	if (ac < 2)
		return (ft_pserc("Error: Not enough argument\n", RED) * 0 + 1);
	if (ft_arg(ac, av, &d) == FALSE)
		return (ft_free_data(&d));
	if (ft_is_sort(&d) == FALSE)
	{
		sorted_index = (d.a);
		ft_stack_sort(&sorted_index);
		ft_indexing(sorted_index, &d);
		if (d.max == 5)
			ft_solve_5(&d);
		ft_solve(&d, 1);
	}
	ft_free_data(&d);
	sorted_index = NULL;
	return (0);
}

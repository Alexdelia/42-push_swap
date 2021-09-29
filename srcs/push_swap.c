/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 19:05:39 by adelille          #+#    #+#             */
/*   Updated: 2021/09/29 16:20:40 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	main(int ac, char **av)
{
	t_data	d;
	t_stack	*sorted_index;

	d.a = NULL;
	d.b = NULL;
	if (ac < 2)
		return (ft_pserc("Error: Not enough argument\n", RED) * 0 + 1);
	if (ft_arg(ac, av, &d) == FALSE)
		return (ft_free_data(&d));
	if (ft_is_sort(&d) == FALSE)
	{
		sorted_index = (d.a);
		// get sorted stack example
		ft_stack_sort(&sorted_index);
		// index based on sorted stack
		ft_indexing(sorted_index, &d);
		// solve
	}

	/*ft_free_arg_list(arg_index);
	ft_free_arg_list(arg_gt);*/
	ft_free_data(&d);
	sorted_index = NULL;
	return (0);
}

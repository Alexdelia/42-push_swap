/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 15:17:56 by adelille          #+#    #+#             */
/*   Updated: 2021/07/13 15:32:15 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_arg_list	*ft_solve(t_markup *a, int (*ma)(t_markup *, t_mt *))
{
	t_arg_list	*arg_list;
	t_markup	*b;

	arg_list = ft_init_arg_list();
	b = ft_init_stack();
	ft_solve_a(a, b, ma, arg_list);
	ft_solve_b(a, b, arg_list);
	ft_align_a(a, arg_list);
	// free b
	return (arg_list);
}

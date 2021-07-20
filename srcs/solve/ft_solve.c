/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 15:17:56 by adelille          #+#    #+#             */
/*   Updated: 2021/07/20 15:16:33 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_free_stack(t_markup *ma)
{
	int		i;
	t_mt	*tmp;
	t_mt	*del;

	i = 0;
	tmp = ma->head;
	while (i < ma->size)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
		i++;
	}
	free(ma);
}

static void	ft_align_a(t_markup *a, t_arg_list *arg_list)
{
	t_mt	*current;
	int		ra_size;
	int		rra_size;

	if (a && a->head)
	{
		ra_size = 0;
		current = a->head;
		while (current->index != 0)
		{
			ra_size++;
			current = current->next;
		}
		rra_size = 0;
		current = a->head;
		while (current->index != 0)
		{
			rra_size++;
			current = current->prev;
		}
		while (a->head->index != 0 && (ra_size < rra_size))
			ft_mt_rx(a, "ra\n" arg_list);
		while (a->head->index != 0 && !(ra_size < rra_size))
			ft_mt_rrx(a, "rra\n", arg_list);
	}
}

t_arg_list	*ft_solve(t_markup *a, int (*ma)(t_markup *, t_mt *))
{
	t_arg_list	*arg_list;
	t_markup	*b;

	arg_list = ft_init_arg_list();
	b = ft_init_stack();
	ft_solve_a(a, b, ma, arg_list);
	ft_solve_b(a, b, arg_list);
	ft_align_a(a, arg_list);
	ft_free_stack(b);
	return (arg_list);
}

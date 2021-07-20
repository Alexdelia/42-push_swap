/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 17:12:03 by adelille          #+#    #+#             */
/*   Updated: 2021/07/20 15:09:05 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static t_sbs	*ft_init_sbs(void)
{
	t_sbs	*sbs;

	sbs = (t_sbs *)ft_memalloc(sizeof(t_sbs));
	if (!sbs)
		ft_exit("Error: Malloc failed in ft_init_sbs");
	sbs->mt_a = NULL;
	sbs->mt_b = NULL;
	sbs->dir_a = R_UP;
	sbs->dir_b = R_UP;
	sbs->size = 0;
	sbs->set = FALSE;
	return (sbs);
}

static void	ft_move_b(t_markup *a, t_markup *b,
			t_sbs *sbs, t_arg_list *arg_list)
{
	while (sbs->mt_a != a->head || sbs->mt_b != b->head)
	{
		if (sbs->dir_a == sbs->dir_b
			&& sbs->mt_a != a->head && sbs->mt_b != b->head)
		{
			if (sbs->dir_a == R_UP)
				ft_mt_rr(a, b, "rr\n", arg_list);
			else
				ft_mt_rrr(a, b, "rrr\n", arg_list);
		}
		else if (sbs->mt_a != a->head)
		{
			if (sbs->dir_a == R_UP)
				ft_mt_rx(a, b, "ra\n", arg_list);
			else
				ft_mt_rrx(a, b, "rra\n", arg_list);
		}
		else if (sbs->mt_b != b->head)
		{
			if (sbs->dir_b == R_UP)
				ft_mt_rx(a, b, "rb\n", arg_list);
			else
				ft_mt_rrx(a, b, "rrb\n", arg_list);
		}
	}
}

void	ft_solve_b(t_markup *a, t_markup *b, t_arg_list *arg_list)
{
	t_sbs	*sbs;

	sbs = ft_init_sbs();
	while (b->size)
	{
		sbs->set = FALSE;
		ft_find_dir(a, b, sbs);
		ft_move_b(a, b, sbs, arg_list);
		ft_px(a, b, "pa\n", arg_list);
	}
	free(sbs);
}

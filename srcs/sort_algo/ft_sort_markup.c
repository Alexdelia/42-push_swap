/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_markup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 14:29:10 by adelille          #+#    #+#             */
/*   Updated: 2021/06/04 06:57:35 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_update_command(char *command, int print, int nb_command)
{
	if (print == TRUE)
		ft_ps(command);
	return (nb_command);
}

static int	ft_a_to_b(t_markup *ma, int res, int type, int print)
{
	while (ft_mt_readindex(ma->a) == 2 || ft_mt_readindex(ma->a) == FALSE)
	{
		if (ft_sa_needed(ma) == TRUE)
		{
			ft_mt_s(ma, MT_A); // do sa
			res += ft_update_command("sa\n", print, 1);
			if (type == 1)
				ft_fill_greater_keep(&ma->a);
			else if (type == 2)
				ft_fill_index_keep(&ma->a);
		}
		else if (ma->a->index == FALSE)
		{
			ft_mt_p(ma, MT_B); // do pb
			res += ft_update_command("pb\n", print, 1);
		}
		else
		{
			ft_mt_r(ma, MT_A); // do ra
			res += ft_update_command("ra\n", print, 1);
		}
	}
	return (res);
}

static int	ft_b_to_a(t_markup *ma, int print)
{
	int			res;
	t_b_to_a	f;

	res = 0;
	while (ma->b)
	{
		f = ft_init_f();
		// choose element in b moving to a
		f = ft_b_to_a_best(*ma, f);
		// move a and b to prepare them for pa with choosen element
		res += ft_b_to_a_move(ma, f, print);
		ft_mt_p(ma, MT_A); // do pa
		res += ft_update_command("pa\n", print, 1); // print if needed
	}
	return (res);
}

int	ft_sort_markup(t_markup *ma, int type, int print)
{
	int		res;

	res = ft_a_to_b(ma, 0, type, print);
	res += ft_b_to_a(ma, print);
	res += ft_align_a(ma, print);
	ft_free_markup(ma);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_markup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 13:57:39 by adelille          #+#    #+#             */
/*   Updated: 2021/05/01 14:42:09 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void	ft_fill_markup(t_markup *ma, t_list *lst)
{
	ma->a = ft_mt_new(lst->data, -1, -1);
	lst = lst->next;
	while (lst)
	{
		ft_mt_addback(&ma->a, ft_mt_new(lst->data, -1, -1));
		lst = lst->next;
	}
}

static void	ft_index_markup(t_markup *ma)
{
	int	biggest_index;
	int	biggest_nb;

	biggest_index = 0;
	biggest_nb = ft_mt_min(ma->a);
	ft_fill_index(&ma->a, biggest_nb, biggest_index);
	while (biggest_index < ft_mt_size(ma->a) - 1)
	{
		biggest_nb = ft_mt_nextmin(ma->a, biggest_nb);
		biggest_index++;
		ft_fill_index(&ma->a, biggest_nb, biggest_index);
	}
}

static void	ft_process_markup(t_markup *ma, int type)
{
	t_mt	*head;

	head = ma->a;
	if (type == 1)
		ft_fill_greater_keep(&ma->a);
	else if (type == 2)
		ft_fill_index_keep(ma);
	ma->a = head;
}

void		ft_init_markup(t_markup *ma, t_arg *arg, int type)
{
	if (arg->v == TRUE)
		ft_ps("Filling ...");
	ft_fill_markup(ma, arg->a);
	if (arg->v == TRUE)
		ft_ps("\tDone\nIndexing ...");
	ft_index_markup(ma);
	if (arg->v == TRUE)
		ft_ps("\tDone\nPreprocessing ...");
	ft_process_markup(ma, type);
	if (arg->v == TRUE)
		ft_ps("\tDone\n");
}

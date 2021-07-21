/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:02:16 by adelille          #+#    #+#             */
/*   Updated: 2021/07/21 22:57:16 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void	ft_fill_stack(t_markup *ma, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_is_int(av[i]) == FALSE || ft_max_min(av[i]) == FALSE)
		{
			ft_free_stack(ma);
			exit(1);
		}
		ft_mt_add(ma, ft_mt_new(ft_atoi(av[i])));
		i++;
	}
}

t_markup	*ft_parse(int ac, char **av)
{
	t_markup	*ma;

	ma = (t_markup *)ft_memalloc(sizeof(t_markup));
	if (!ma)
		ft_exit("Error: Malloc failed\n");
	ma->head = NULL;
	ma->markup_head = NULL;
	ma->size = 0;
	ma->pairs = 0;
	ft_fill_stack(ma, ac, av);
	if (!ma->size)
		ft_exit("Error: No int in argument\n");
	return (ma);
}

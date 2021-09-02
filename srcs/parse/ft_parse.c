/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:02:16 by adelille          #+#    #+#             */
/*   Updated: 2021/07/23 17:10:11 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void	ft_split_free(char ***split)
{
	char	**tmp;

	if (split && *split)
	{
		tmp = ((*split));
		while ((*tmp))
			free((*(tmp++)));
		free((*split));
		(*split) = NULL;
	}
}

static void	ft_parse_arr(t_markup *ma, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!ft_isint_s(av[i], FALSE))
		{
			ft_free_stack(ma);
			exit(1);
		}
		ft_mt_add(ma, ft_mt_new(ft_atoi(av[i])));
		i++;
	}
}

static void	ft_parse_str(t_markup *ma, char *str)
{
	char	**nb;
	int		i;

	nb = ft_split(str, ' ');
	i = 0;
	while (nb[i])
	{
		if (!ft_isint_s(nb[i], FALSE))
		{
			ft_free_stack(ma);
			exit(1);
		}
		ft_mt_add(ma, ft_mt_new(ft_atoi(nb[i])));
		i++;
	}
	ft_split_free(&nb);
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
	if (ac == 2 && !ft_isnum_s(av[1], 10))
		ft_parse_str(ma, av[1]);
	else
		ft_parse_arr(ma, ac, av);
	if (!ma->size)
		ft_exit("Error: No int in argument\n");
	return (ma);
}

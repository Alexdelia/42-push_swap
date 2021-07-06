/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:02:16 by adelille          #+#    #+#             */
/*   Updated: 2021/07/06 16:16:53 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void	ft_parse_str(t_markup *ma, char *str)
{
	char	**nb;
	int		i;

	nb = ft_split(str, ' ');
	i = 0;
	while (nb[i])
	{
		// check int
		// fill ma
	}
	// free split
}

t_markup	*ft_parse(int ac, char **av)
{
	t_markup	*ma;

	ma = (t_markup *)ft_memalloc(sizeof(t_markup))
	if (!ma)
		ft_exit("Error: Malloc failed\n");
	ma->head = NULL;
	ma->markup_head = NULL;
	ma->size = 0;
	ma->pairs = 0;
	if (ac == 2 && !(av[1] >= '0' && av[1] <= '9'))
		ft_parse_str(ma, av[1]);
	else
		ft_parse_arr(ma, ac, av);
	if (!ma->size)
		ft_exit("Error: No int in argument\n");
	return (ma);
}

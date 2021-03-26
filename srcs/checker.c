/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:05:39 by adelille          #+#    #+#             */
/*   Updated: 2021/03/26 00:58:41 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_visual(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_strcmp(av[i], "-v") == 0)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	main(int ac, char **av)
{
	t_arg	arg;
	int	v;

	v = ft_visual(av);
	if (v == TRUE)
		ft_psc("\nParsing ...\t", "\033[1;29m");
	ft_arg(&arg, ac, av);
	if (arg.err == TRUE)
		return (0);
	if (v == TRUE)
	{
		ft_psc("Done\n", GRN);
		ft_psc("\nPlease enter commands:\n", "\033[1;29m");
	}
	ft_checking(&arg);
	ft_lstclear(&arg.a);
	ft_lstclear(&arg.b);
	return (0);
}

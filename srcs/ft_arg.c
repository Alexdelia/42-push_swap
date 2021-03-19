/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:35:30 by adelille          #+#    #+#             */
/*   Updated: 2021/03/19 16:21:07 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int		ft_is_int(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int		ft_fret(t_list a)
{
	ft_lstclear(a);
	return (FALSE);
}

int		ft_arg(int ac, char **av, t_list a);
{
	int		i;

	i = 1;
	if (av[1] && ft_is_int(av[1]) == TRUE)
	{
		a->data = ft_atoi(av[1]);
		i++;
	}
	while (av[i])
	{
		if (ft_is_int(av[i]) == FALSE)
			return (ft_fret(a));
		ft_lstadd_back(a, ft_lstnew(ft_atoi(av[i])));
		i++;
	}
	return (TRUE);
}

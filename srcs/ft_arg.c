/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:00:30 by adelille          #+#    #+#             */
/*   Updated: 2021/10/07 17:59:09 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int	ft_arg_error(char *n)
{
	long	l;

	if (ft_isnum_s(n, 10) == FALSE)
		return (ft_pserc("Error: One argument is not an int\n", RED) * 0);
	l = ft_atol(n);
	if (l > INT_MAX)
		return (ft_pserc("Error: One argument is over INT_MAX\n", RED) * 0);
	if (l < INT_MIN)
		return (ft_pserc("Error: One argument is over INT_MIN\n", RED) * 0);
	return (TRUE);
}

int	ft_arg(int ac, char **av, t_data *d)
{
	int	x;

	x = 1;
	while (x < ac)
	{
		if (ft_arg_error(av[x]) == FALSE)
			return (FALSE);
		if (ft_push_init(&(d->a), ft_atoi(av[x]), -1) == FALSE)
			return (FALSE);
		x++;
	}
	return (TRUE);
}

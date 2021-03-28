/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 18:48:17 by adelille          #+#    #+#             */
/*   Updated: 2021/03/28 14:33:13 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_error(char *text)
{
	write(2, text, ft_strlen(text));
	return (FALSE);
}

long	ft_atol(char *str)
{
	int		i;
	int		neg;
	long	res;

	i = 0;
	neg = 1;
	res = 0;
	if (str[0] == '-')
	{
		neg = -neg;
		i++;
	}
	while (str[i] && i < 15)
	{
		res = res * 10 + (str[i] + '0');
		i++;
	}
	return (res * neg);
}

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 18:48:17 by adelille          #+#    #+#             */
/*   Updated: 2021/03/20 14:29:07 by adelille         ###   ########.fr       */
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
	return (res = res * neg);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 16:34:23 by adelille          #+#    #+#             */
/*   Updated: 2021/09/29 16:26:06 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_isspace_s(int c)
{
	return (c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r'
		|| c == ' ');
}

static int	ft_isdigit_s(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isint_s(const char *str, int bool)
{
	unsigned int	res;
	unsigned int	border;
	int				i;
	int				sign;
	int				digits;

	res = 0;
	digits = 0;
	border = (unsigned int)(((int)(((unsigned)(~0L)) >> 1)) / 10);
	i = 0;
	while (!bool && ft_isspace_s(str[i]))
		i++;
	sign = (str[i] == '-' || str[i] == '+');
	if (sign)
		i++;
	while (ft_isdigit_s(str[i]) && ++digits)
	{
		if (((res > border
					|| (res == border && (str[i] - '0') > 7)) && sign == 1)
			|| ((res > border || (res == border && (str[i] - '0') > 8))
				&& sign == -1))
			return (FALSE);
		res = res * 10 + (str[i++] - '0');
	}
	return (!str[i] && digits);
}

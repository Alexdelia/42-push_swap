/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 19:13:39 by adelille          #+#    #+#             */
/*   Updated: 2021/05/01 12:08:54 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_is_int(char *str)
{
	int	i;

	if (ft_strcmp(str, "-c") == 0 || ft_strcmp(str, "-v") == 0)
		return (TRUE);
	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (ft_error("Error: one of the parameters is not an int.\n"));
		i++;
	}
	return (TRUE);
}

int	ft_isnt_in(t_list *lst, int nb)
{
	while (lst)
	{
		if (nb == lst->data)
			return (ft_error("Error: one int is present multiple times\n"));
		lst = lst->next;
	}
	return (TRUE);
}

int	ft_max_min_in(t_list *a, char *str)
{
	if (atol(str) > INT_MAX)
		return (ft_error("Error: one int is over INT_MAX\n"));
	if (atol(str) < INT_MIN)
		return (ft_error("Error: one int is under INT_MIN\n"));
	if (ft_isnt_in(a, ft_atoi(str)) == FALSE)
		return (FALSE);
	return (TRUE);
}

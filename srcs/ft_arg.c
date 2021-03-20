/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:35:30 by adelille          #+#    #+#             */
/*   Updated: 2021/03/20 15:53:18 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int	ft_is_int(char *str)
{
	int	i;

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

static int	ft_isnt_in(t_list *lst, int nb)
{
	while (lst)
	{
		if (nb == lst->data)
			return (ft_error("Error: one int is present multiple times\n"));
		lst = lst->next;
	}
	return (TRUE);
}

int	ft_fret(t_list **a)
{
	ft_lstclear(a);
	return (FALSE);
}

static int	ft_max_min_in(t_list *a, char *str)
{
	if (atol(str) > INT_MAX)
		return (ft_error("Error: one int is over INT_MAX\n"));
	if (atol(str) < INT_MIN)
		return (ft_error("Error: one int is under INT_MIN\n"));
	if (ft_isnt_in(a, ft_atoi(str)) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	ft_arg(int ac, char **av, t_list *a)
{
	int		i;

	(void)ac;
	i = 1;
	if (av[1] && ft_is_int(av[1]) == TRUE)
	{
		a->data = ft_atoi(av[1]);
		i++;
	}
	while (av[i])
	{
		if (ft_is_int(av[i]) == FALSE)
			return (ft_fret(&a));
		if (ft_max_min_in(a, av[i]) == FALSE)
			return (ft_fret(&a));
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(av[i])));
		i++;
	}
	return (TRUE);
}

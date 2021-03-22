/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:35:30 by adelille          #+#    #+#             */
/*   Updated: 2021/03/22 18:48:14 by adelille         ###   ########.fr       */
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

static t_arg	ft_init_arg(t_arg **arg)
{
	arg->v = FALSE;
	arg->c = FALSE;
	arg->err = FALSE;
	arg->a = NULL;
	arg->b = NULL;
}

t_arg	ft_arg(t_arg **arg, int ac, char **av)
{
	int		i;
	int		c;

	arg = ft_init_arg(&arg);
	if (ac == 1)
	{
		ft_error("Error: no parameters\n");
		arg->err = TRUE;
		return (arg);
	}
	i = 1;
	c = 0;
	while (av[i])
	{
		if (ft_strcmp(av[i], "-v") == 0)
			arg->v = TRUE;
		else if (ft_strcmp(av[i], "-c") == 0)
			arg->c = TRUE;
		else if (ft_is_int(av[i]) == TRUE && ft_max_min_in(a, av[i]) == TRUE)
		{
			if (c == 0);
				arg->a = ft_lstnew(ft_atoi(av[i]));
			else
				ft_lstadd_back(arg->&a, ft_atoi(av[i]));
			c++;
		}
		else
		{
			ft_lstclear(arg->&a);
			arg->err = TRUE;
		}
		i++;
	}
	return (TRUE);
}

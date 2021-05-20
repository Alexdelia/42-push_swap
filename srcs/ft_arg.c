/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:35:30 by adelille          #+#    #+#             */
/*   Updated: 2021/05/20 22:48:22 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_init_arg(t_arg *arg)
{
	arg->v = FALSE;
	arg->c = FALSE;
	arg->err = FALSE;
	arg->a = NULL;
	arg->b = NULL;
}

void	ft_hyphen(t_arg *arg, char *str)
{
	if (ft_strcmp(str, "-v") == 0)
		arg->v = TRUE;
	if (ft_strcmp(str, "-c") == 0)
		arg->c = TRUE;
}

int	ft_loop(t_arg *arg, char *str, int c)
{
	if (str[0] == '-')
		ft_hyphen(arg, str);
	if (ft_is_int(str) == TRUE && ft_max_min_in(arg->a, str) == TRUE
		&& ft_strcmp(str, "-v") != 0 && ft_strcmp(str, "-c") != 0)
	{
		if (c == 0)
			arg->a = ft_lstnew(ft_atoi(str));
		else
			ft_lstadd_back(&arg->a, ft_lstnew(ft_atoi(str)));
		c++;
	}
	else if (ft_strcmp(str, "-v") != 0 && ft_strcmp(str, "-c") != 0)
	{
		ft_lstclear(&arg->a);
		arg->err = TRUE;
	}
	return (c);
}

int	ft_arg(t_arg *arg, int ac, char **av)
{
	int		i;
	int		c;

	ft_init_arg(arg);
	if (ac == 1)
	{
		arg->err = !ft_error("Error: no parameters\n");
		return (TRUE);
	}
	i = 1;
	c = 0;
	while (av[i] && arg->err == FALSE)
	{
		c = ft_loop(arg, av[i], c);
		i++;
	}
	return (TRUE);
}

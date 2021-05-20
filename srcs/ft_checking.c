/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 14:35:14 by adelille          #+#    #+#             */
/*   Updated: 2021/05/20 22:49:06 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_dor(t_arg *arg, char *line)
{
	int	err;

	err = 0;
	if (ft_strcmp(line, "ra") == 0)
		err = ft_op_r(&arg->a) + ft_lst_color(*arg, ft_lstsize(arg->a), 0);
	else if (ft_strcmp(line, "rb") == 0)
		err = ft_op_r(&arg->b) + ft_lst_color(*arg, 0, ft_lstsize(arg->b));
	else if (ft_strcmp(line, "rr") == 0)
		err = ft_op_r(&arg->a) + ft_op_r(&arg->b)
			+ ft_lst_color(*arg, ft_lstsize(arg->a), ft_lstsize(arg->b));
	else if (ft_strcmp(line, "rra") == 0)
		err = ft_op_rr(&arg->a) + ft_lst_color(*arg, 1, 0);
	else if (ft_strcmp(line, "rrb") == 0)
		err = ft_op_rr(&arg->b) + ft_lst_color(*arg, 0, 1);
	else if (ft_strcmp(line, "rrr") == 0)
		err = ft_op_rr(&arg->a) + ft_op_rr(&arg->b)
			+ ft_lst_color(*arg, 1, 1);
	else
	{
		err = 1;
		ft_error("Error: command \"");
		ft_error(line);
		ft_error("\" doesn't exist.\n");
	}
	return (err);
}

int	ft_doop(t_arg *arg, char *line)
{
	int	err;

	err = 0;
	if (ft_strcmp(line, "sa") == 0)
		err = ft_op_sa(arg) + ft_lst_color_sa(*arg);
	else if (ft_strcmp(line, "sb") == 0)
		err = ft_op_sb(arg) + ft_lst_color_sb(*arg);
	else if (ft_strcmp(line, "ss") == 0)
		err = ft_op_sa(arg) + ft_op_sb(arg) + ft_lst_color_ss(*arg);
	else if (ft_strcmp(line, "pa") == 0)
		err = ft_op_p(&arg->a, &arg->b) + ft_lst_color(*arg, 1, 0);
	else if (ft_strcmp(line, "pb") == 0)
		err = ft_op_p(&arg->b, &arg->a) + ft_lst_color(*arg, 0, 1);
	else if (line[0] == 'r')
		err = ft_dor(arg, line);
	else
	{
		err = 1;
		ft_error("Error: command \"");
		ft_error(line);
		ft_error("\" doesn't exist.\n");
	}
	return (err);
}

void	ft_output(t_arg arg)
{
	if (arg.b || ft_check_sort(arg.a) == FALSE)
	{
		if (arg.c == TRUE)
			ft_psc("KO\n", RED);
		else
			ft_ps("KO\n");
	}
	else
	{
		if (arg.c == TRUE)
			ft_psc("OK\n", GRN);
		else
			ft_ps("OK\n");
	}
}

int	ft_checking(t_arg *arg)
{
	char	*line;

	while ((get_next_line(0, &line) > 0))
	{
		if (ft_doop(arg, line) >= 1)
		{
			free(line);
			return (FALSE);
		}
		free(line);
	}
	if (line)
		free(line);
	ft_output(*arg);
	return (TRUE);
}

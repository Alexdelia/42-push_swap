/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:05:39 by adelille          #+#    #+#             */
/*   Updated: 2021/10/10 17:37:20 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int	ft_do_op(char *op, t_data *d)
{
	if (!ft_strcmp(op, "sa"))
		ft_sa(d);
	else if (!ft_strcmp(op, "sb"))
		ft_sb(d);
	else if (!ft_strcmp(op, "ss"))
		ft_ss(d);
	else if (!ft_strcmp(op, "pa"))
		ft_pa(d);
	else if (!ft_strcmp(op, "pb"))
		ft_pb(d);
	else if (!ft_strcmp(op, "ra"))
		ft_ra(d);
	else if (!ft_strcmp(op, "rb"))
		ft_rb(d);
	else if (!ft_strcmp(op, "rr"))
		ft_rr(d);
	else if (!ft_strcmp(op, "rra"))
		ft_rra(d);
	else if (!ft_strcmp(op, "rrb"))
		ft_rrb(d);
	else if (!ft_strcmp(op, "rrr"))
		ft_rrr(d);
	else
		return (FALSE);
	return (TRUE);
}

static int	ft_read_operation(t_data *d)
{
	char	op[4];
	int		i;
	int		p;

	 i = 0;
	 while (i < 4)
	 {
		 p = i;
		 i += read(0, op + i, 1);
		 if (p == i)
			break ;
		 if (op[p] == '\n')
		 {
			 op[p] = 0;
			 if (ft_do_op(op, d) == FALSE)
				 return (FALSE);
			 i = 0;
		 }
	 }
	 if (i == 4)
		 return (FALSE);
	 return (TRUE);
}

int	main(int ac, char **av)
{
	t_data	d;

	d.a = NULL;
	d.b = NULL;
	d.print = 0;
	/*if (v == TRUE)
		ft_psc("\nParsing ...\t", "\033[1;29m");*/
	if (ft_arg(ac, av, &d) == FALSE)
		return (ft_free_data(&d));
	if (ft_read_operation(&d) == FALSE)
		return (ft_free_data(&d));
	/*if (v == TRUE)
	{
		ft_psc("Done\n", GRN);
		ft_psc("\nPlease enter commands:\n", "\033[1;29m");
	}*/
	if (ft_is_sort(&d) == TRUE)
		ft_ps("OK\n");
	else
		ft_ps("KO\n");
	ft_free_data(&d);
	return (0);
}

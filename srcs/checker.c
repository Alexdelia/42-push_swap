/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:05:39 by adelille          #+#    #+#             */
/*   Updated: 2021/10/10 17:28:47 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int	ft_do_op(char *op, t_data *d)
{
	if (!ft_strcmp(name, "sa"))
		swap_a(mem);
	else if (!ft_strcmp(name, "sb"))
		swap_b(mem);
	else if (!ft_strcmp(name, "ss"))
		swap_b_a(mem);
	else if (!ft_strcmp(name, "pa"))
		push_a(mem);
	else if (!ft_strcmp(name, "pb"))
		push_b(mem);
	else if (!ft_strcmp(name, "ra"))
		rotate_a(mem);
	else if (!ft_strcmp(name, "rb"))
		rotate_b(mem);
	else if (!ft_strcmp(name, "rr"))
		rotate_b_a(mem);
	else if (!ft_strcmp(name, "rra"))
		rev_rotate_a(mem);
	else if (!ft_strcmp(name, "rrb"))
		rev_rotate_b(mem);
	else if (!ft_strcmp(name, "rrr"))
		rev_rotate_b_a(mem);
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
	t_data	*d;

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
		ft_ps("OK");
	else
		ft_ps("KO");
	ft_free_data(&d);
	return (0);
}

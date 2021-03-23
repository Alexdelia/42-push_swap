/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:05:39 by adelille          #+#    #+#             */
/*   Updated: 2021/03/23 21:20:52 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_pl(t_list *a)
{
	while (a)
	{
		ft_ps(ft_itoa(a->data));
		ft_ps("\n");
		a = a->next;
	}
}

int	main(int ac, char **av)
{
	t_arg	arg;

	ft_psc("\nParsing ...\t", "\033[1;29m");
	ft_arg(&arg, ac, av);
	if (arg.err == TRUE)
		return (0);
	ft_psc("Done\n", GRN);
	ft_psc("\nPlease enter the command:\n", "\033[1;29m");
	if (ft_checking(&arg) == FALSE)
		//WIP
	//ft_pl(a);
	ft_lstclear(&arg.a);
	ft_lstclear(&arg.b);
	return (0);
}

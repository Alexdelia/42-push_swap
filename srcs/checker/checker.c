/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:05:39 by adelille          #+#    #+#             */
/*   Updated: 2021/10/10 17:22:26 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

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

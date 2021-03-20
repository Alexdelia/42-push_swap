/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:05:46 by adelille          #+#    #+#             */
/*   Updated: 2021/03/20 14:44:25 by adelille         ###   ########.fr       */
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

// int overflow bad handled
int		main(int ac, char **av)
{
	t_list	*a;

	a = ft_lstnew(0);
	ft_ps("Parsing ...\t");
	if (ft_arg(ac, av, a) == FALSE)
		return (0);
	ft_ps("Done\n");
	ft_pl(a);
	ft_lstclear(&a);
	return (0);
}

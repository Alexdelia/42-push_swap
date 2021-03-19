/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:05:46 by adelille          #+#    #+#             */
/*   Updated: 2021/03/19 21:10:01 by adelille         ###   ########.fr       */
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
	if (ft_arg(ac, av, a) == FALSE)
		return (0);
	ft_pl(a);
	ft_lstclear(&a);
	return (0);
}

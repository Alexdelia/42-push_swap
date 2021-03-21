/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:05:39 by adelille          #+#    #+#             */
/*   Updated: 2021/03/21 15:09:23 by adelille         ###   ########.fr       */
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
int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = ft_lstnew(0);
	ft_psc("\nParsing ...\t", "\033[1;29m");
	if (ft_arg(ac, av, a) == FALSE)
		return (0);
	ft_psc("Done\n", GRN);
	b = (t_list *)malloc(sizeof(*b));
	if (!b)
		return (0);
	b->next = NULL;
	ft_psc("\nPlease enter the command:\n", "\033[1;29m");
	if (ft_checking(&a, &b) == FALSE)
		//WIP
	//ft_pl(a);
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:05:46 by adelille          #+#    #+#             */
/*   Updated: 2021/03/19 19:09:44 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_pl(a)
{
	
}

int		main(int ac, char **av)
{
	t_list	a;

	a = ft_lstnew(0);
	if (ft_arg(ac, av, a) == FALSE)
		return (0);
	ft_pl(a);
	ft_lstclear(a);
	return (0);
}

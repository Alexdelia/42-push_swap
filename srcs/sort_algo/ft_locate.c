/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_locate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 02:05:28 by adelille          #+#    #+#             */
/*   Updated: 2021/03/27 03:59:13 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_lst_last(t_list *lst, int data)
{
	while (lst && lst->next)
	{
		//ft_ps(ft_itoa(lst->data));
		if (lst->data == data)
			return (FALSE);
		lst = lst->next;
	}
	//ft_ps(ft_itoa(lst->data));
	//ft_ps(ft_itoa(data));
	if (lst->data == data)
		return (TRUE);
	return (FALSE);
}

int	ft_find_close(t_list *lst, int data)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(lst);
	while (lst && lst->data != data)
	{
		i++;
		lst = lst->next;
	}
	return ((i > size / 2 ? 1 : -1));
}

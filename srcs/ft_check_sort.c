/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 04:43:54 by adelille          #+#    #+#             */
/*   Updated: 2021/03/26 00:21:47 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_check_sort(t_list *lst)
{
	while (lst && lst->next)
	{
		if (lst->data > lst->next->data)
			return (FALSE);
		lst = lst->next;
	}
	return (TRUE);
}

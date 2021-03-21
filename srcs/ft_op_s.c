/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 15:27:35 by adelille          #+#    #+#             */
/*   Updated: 2021/03/21 15:33:51 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_s(t_list **lst)
{
	t_list	*next;
	int		tmp;

	next = lst->next;
	if (!lst || !lst->data || !next || !next->data)
		return (0);
	tmp = next->data;
	next->data = lst->data;
	lst->data = tmp;
	return (0);
}

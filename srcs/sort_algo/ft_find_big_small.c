/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_big_small.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 02:03:13 by adelille          #+#    #+#             */
/*   Updated: 2021/03/27 03:27:20 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_smallest(t_list *lst)
{
	int smallest;

	smallest = INT_MAX;
	while (lst)
	{
		if (lst->data < smallest)
			smallest = lst->data;
		lst = lst->next;
	}
	return (smallest);
}

int	ft_biggest(t_list *lst)
{
	int	biggest;

	biggest = INT_MIN;
	while (lst)
	{
		if (lst->data > biggest)
			biggest = lst->data;
		lst = lst->next;
	}
	return (biggest);
}

int	ft_next_small(t_list *lst, int last_small)
{
	int small;

	small = INT_MAX;
	while (lst)
	{
		if (lst->data < small && lst->data > last_small)
			small = lst->data;
		lst = lst->next;
	}
	return (small);
}

int ft_next_big(t_list *lst, int last_big)
{
	int big;

	big = INT_MIN;
	while (lst)
	{
		if (lst->data > big && lst->data < last_big)
			big = lst->data;
		lst = lst->next;
	}
	return (big);
}

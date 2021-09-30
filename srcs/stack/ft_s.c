/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:13:45 by adelille          #+#    #+#             */
/*   Updated: 2021/09/30 18:15:07 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_s(t_stack **x, t_stack *y)
{
	t_stack	*tmp;

	tmp = *x;
	*x = y->next_sort;
	tmp->next_sort = y->next_sort->next_sort;
	(*x)->next_sort = tmp;
}

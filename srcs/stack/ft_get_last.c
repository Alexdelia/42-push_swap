/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:51:05 by adelille          #+#    #+#             */
/*   Updated: 2021/10/06 15:52:21 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_stack	*ft_get_last(t_stack *s)
{
	if (s == NULL)
		return (NULL);
	while (s->next)
		s = s->next;
	return (s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:15:26 by adelille          #+#    #+#             */
/*   Updated: 2021/03/20 15:52:32 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int data)
{
	t_list	*elt;

	elt = (t_list *)malloc(sizeof(*elt));
	if (!elt)
		return (NULL);
	elt->data = data;
	elt->next = NULL;
	return (elt);
}

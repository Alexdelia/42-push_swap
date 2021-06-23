/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mt_readindex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 14:40:13 by adelille          #+#    #+#             */
/*   Updated: 2021/06/15 18:30:01 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_mt_readindex(t_mt *mt)
{
	int		t;
	int		f;

	t = FALSE;
	f = FALSE;
	while (mt)
	{
		if (mt->index == TRUE)
			t = TRUE;
		else if (mt->index == FALSE)
			f = TRUE;
		if (t == TRUE && f == TRUE)
			return (2);
		mt = mt->next;
	}
	if (t == TRUE && f == TRUE)
		return (2);
	else if (t == TRUE && f == FALSE)
		return (TRUE);
	else if (t == FALSE && f == TRUE)
		return (FALSE);
	return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:58:11 by adelille          #+#    #+#             */
/*   Updated: 2021/03/21 15:06:05 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include <limits.h>
# include "libft.h"

int		ft_arg(int ac, char **av, t_list *a);

int		ft_checking(t_list **a, t_list **b);

int		ft_error(char *text);
long	ft_atol(char *str);

#endif

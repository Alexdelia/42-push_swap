/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:58:11 by adelille          #+#    #+#             */
/*   Updated: 2021/03/20 14:29:29 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include <limits.h>
# include "libft.h"

# define TRUE 1
# define FALSE 0

int		ft_arg(int ac, char **av, t_list *a);

int		ft_error(char *text);
long	ft_atol(char *str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:58:11 by adelille          #+#    #+#             */
/*   Updated: 2021/03/23 20:12:25 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include <limits.h>
# include "libft.h"

typedef struct	s_arg
{
	int	v;
	int	c;
	int	err;
	t_list	*a;
	t_list	*b;
}

int		ft_arg(int ac, char **av, t_list *a);

int		ft_checking(t_list **a, t_list **b);

int		ft_s(t_list **lst);
int		ft_p(t_list **dst, t_list **src);
int		ft_r(t_list **lst);

int		ft_lst_color(t_arg arg, int ga, int gb);
int		ft_lst_color_sa(t_arg arg);
int		ft_lst_color_sb(t_arg arg);
int		ft_lst_color_ss(t_arg arg);

int		ft_error(char *text);
long	ft_atol(char *str);

#endif

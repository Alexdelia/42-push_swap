/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:58:11 by adelille          #+#    #+#             */
/*   Updated: 2021/03/24 04:47:26 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include <limits.h>
# include "libft.h"

typedef struct s_arg
{
	int		v;
	int		c;
	int		err;
	t_list	*a;
	t_list	*b;
}				t_arg;

int		ft_arg(t_arg *arg, int ac, char **av);

int		ft_checking(t_arg *arg);

int		ft_check_sort(t_list *lst);

int		ft_op_sa(t_arg *arg);
int		ft_op_sb(t_arg *arg);
int		ft_op_p(t_list **dst, t_list **src);
int		ft_op_r(t_list **lst);
int		ft_op_rr(t_list **lst);

int		ft_lst_color(t_arg arg, int ga, int gb);
int		ft_lst_color_sa(t_arg arg);
int		ft_lst_color_sb(t_arg arg);
int		ft_lst_color_ss(t_arg arg);
void	ft_put_row(t_arg arg, int ga, int gb, int i);
void	ft_put_row_sa(t_arg arg, int i);
void	ft_put_row_sb(t_arg arg, int i);
void	ft_put_row_ss(t_arg arg, int i);

int		ft_error(char *text);
long	ft_atol(char *str);

#endif

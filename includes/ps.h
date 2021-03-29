/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:58:11 by adelille          #+#    #+#             */
/*   Updated: 2021/03/29 15:59:39 by adelille         ###   ########.fr       */
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
	t_list	*chunk;
}				t_arg;

int		ft_arg(t_arg *arg, int ac, char **av);
int		ft_is_int(char *str);
int		ft_isnt_in(t_list *lst, int nb);
int		ft_max_min_in(t_list *a, char *str);

int		ft_checking(t_arg *arg);

int		ft_find_best_algo(t_arg *arg);
int		ft_sort_3(t_arg *arg);
int		ft_mid_sort(t_arg *arg);

int		ft_advance_separate(t_arg *arg);

int		ft_first_chunk(t_arg *arg, int data);
int		ft_mid_chunk(t_arg *arg, int data);
int		ft_last_chunk(t_arg *arg, int data);

int		ft_opti_bot(t_list **lst, int data, int v, char *type);
int		ft_opti_top(t_list **lst, int data, int v, char *type);
int		ft_opti_shared_r(t_list **lst, int v, char *type);
int		ft_opti_shared_rr(t_list **lst, int v, char *type);

int		ft_lst_last(t_list *lst);
int		ft_find_close(t_list *lst, int data);
int		ft_lst_under_exist(t_list *lst, int data);

int		ft_smallest(t_list *lst);
int		ft_biggest(t_list *lst);
int		ft_next_small(t_list *lst, int last_small);
int		ft_next_big(t_list *lst, int last_big);

int		ft_check_sort(t_list *lst);
int		ft_check_unsort(t_list *lst);

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
int		ft_visual(char **av);

#endif

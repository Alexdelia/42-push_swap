/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille </var/mail/adelille>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:58:11 by adelille          #+#    #+#             */
/*   Updated: 2021/05/19 19:14:37 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include <limits.h>
# include "libft.h"

# define MT_A	0
# define MT_B	1

typedef struct	s_arg
{
	int			v;
	int			c;
	int			err;
	t_list		*a;
	t_list		*b;
	t_list		*chunk;
}				t_arg;

typedef struct				s_markup_list
{
	int						nb;
	int						index;
	int						keep;
	struct s_markup_list	*next;
}							t_mt;

typedef struct	s_markup
{
	t_mt		*a;
	t_mt		*b;
}				t_markup;

int		ft_arg(t_arg *arg, int ac, char **av);
int		ft_is_int(char *str);
int		ft_isnt_in(t_list *lst, int nb);
int		ft_max_min_in(t_list *a, char *str);

int		ft_checking(t_arg *arg);

int		ft_find_best_algo(t_arg *arg);
int		ft_sort_3(t_arg *arg);
int		ft_mid_sort(t_arg *arg);

void	ft_fill_greater_keep(t_mt **lst);
int		ft_sort_greater(t_arg *arg, int print);

void	ft_fill_index_keep(t_mt **lst);
int		ft_sort_index(t_arg *arg, int print);

void	ft_init_markup(t_markup *ma, t_arg *arg, int type);
int		ft_fill_index(t_mt **mt, int nb, int index);
int		ft_sort_markup(t_markup *ma, int type, int print);
int		ft_sa_needed(t_markup *mt);
int		ft_total_keep(t_mt *mt);

t_mt	*ft_mt_new(int nb, int index, int keep);
void	ft_mt_addback(t_mt **alst, t_mt *new);
int		ft_mt_size(t_mt *lst);
t_mt	*ft_mt_last(t_mt *lst);
int		ft_mt_min(t_mt *mt);
int		ft_mt_nextmin(t_mt *mt, int over);
int		ft_mt_readindex(t_mt *mt);

void	ft_mt_s(t_markup *mt, int type);
void	ft_mt_ss(t_markup *mt);
void	ft_mt_p(t_markup *mt, int type);
void	ft_mt_r(t_markup *mt, int type);
//void	ft_mt_rr(t_markup *mt, int type);

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille </var/mail/adelille>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:58:11 by adelille          #+#    #+#             */
/*   Updated: 2021/07/21 23:12:34 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include <limits.h>
# include "libft.h"

# define MT_A	0
# define MT_B	1

# define R_UP	1
# define R_DOWN	-1

typedef struct s_arg
{
	char			*name;
	struct s_arg	*next;
}					t_arg;

typedef struct s_arg_list
{
	int			size;
	t_arg		*head;
}				t_arg_list;

typedef struct s_markup_list
{
	int						nb;
	int						index;
	int						keep;
	struct s_markup_list	*prev;
	struct s_markup_list	*next;
}							t_mt;

typedef struct s_markup
{
	int			size;
	int			pairs;
	t_mt		*head;
	t_mt		*markup_head;
}				t_markup;

typedef struct s_solve_b_shift
{
	t_mt	*mt_a;
	t_mt	*mt_b;
	int		dir_a;
	int		dir_b;
	int		size;
	int		set;
}			t_sbs;

typedef struct s_rotate_size
{
	int		ra;
	int		rra;
	int		rb;
	int		rrb;
}			t_rxs;

typedef struct s_b_to_a
{
	int			b;
	int			a;
	int			r;
}				t_b_to_a;

void	ft_check_duplicate(t_markup	*ma);

int		ft_arg(t_arg *arg, int ac, char **av);
int		ft_is_int(char *str);
int		ft_isnt_in(t_list *lst, int nb);
int		ft_max_min_in(t_list *a, char *str);
int		ft_max_min(char *str);

int		ft_checking(t_arg *arg);

int		ft_sort_3(t_arg *arg);

t_mt	*ft_mt_new(int nb);
void	ft_mt_add(t_markup *ma, t_mt *new);

int		ft_mt_size(t_mt *lst);
int		ft_mt_min(t_mt *mt);
int		ft_mt_nextmin(t_mt *mt, int over);
int		ft_mt_readindex(t_mt *mt);
void	ft_mt_free(t_mt *mt);
void	ft_mt_freeall(t_mt **mt);

t_markup	*ft_init_stack(void);
t_arg_list	*ft_init_arg_list(void);

t_arg	*ft_create_command(char *name);
void	ft_add_command(t_arg_list *arg_list, t_arg *arg);
void	ft_print_commands(t_arg_list *arg_list);
void	ft_free_arg_list(t_arg_list *arg_list);

t_markup	*ft_parse(int ac, char **av);
void	ft_index(t_markup *ma);

void	ft_markup_option(t_markup *ma, int (*ft_markup_s)(t_markup *, t_mt *));
int		ft_markup_index(t_markup *ma, t_mt *head);
int		ft_markup_gt(t_markup *ma, t_mt *head);

t_arg_list	*ft_solve(t_markup *a, int (*ma)(t_markup *, t_mt *));
void	ft_solve_a(t_markup *a, t_markup *b, int (*ft_ma)(t_markup *, t_mt *), t_arg_list *arg_list);
void	ft_solve_b(t_markup *a, t_markup *b, t_arg_list *arg_list);
void	ft_find_dir(t_markup *a, t_markup *b, t_sbs *sbs);

void	ft_mt_sx(t_markup *ma, char *name, t_arg_list *arg_list);
void	ft_mt_ss(t_markup *a, t_markup *b, char *name, t_arg_list *arg_list);
void	ft_mt_p(t_markup *dst, t_markup *src, char *name, t_arg_list *arg_list);
void	ft_mt_rx(t_markup *ma, char *name, t_arg_list *arg_list);
void	ft_mt_rr(t_markup *a, t_markup *b,  char *name, t_arg_list *arg_list);
void	ft_mt_rrx(t_markup *ma, char *name, t_arg_list *arg_list);
void	ft_mt_rrr(t_markup *a, t_markup *b,  char *name, t_arg_list *arg_list);

void	ft_push(t_markup *ma, t_mt *mt);
t_mt	*ft_pop(t_markup *ma);

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

void	ft_exit(char *text);
int		ft_error(char *text);
void	*ft_memalloc(size_t size);
long	ft_atol(char *str);
int		ft_visual(char **av);
int		ft_max(int x, int y);
void	ft_free_stack(t_markup *ma);

#endif

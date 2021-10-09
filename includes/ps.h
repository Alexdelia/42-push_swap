/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille </var/mail/adelille>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:58:11 by adelille          #+#    #+#             */
/*   Updated: 2021/10/09 19:45:30 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include <limits.h>
# include "libft.h"
// to remove
# include <stdio.h>

typedef struct s_stack
{
	long			data;
	int				index;
	int				keep;
	struct s_stack	*next;
	struct s_stack	*next_sort;
}					t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*tmp;
	int		max;
	int		big;
	int		size;
	int		group_count;
	int		group_size;
	int		operation_count;
	int		print;
}			t_data;

int		ft_arg(int ac, char **av, t_data *d);
int		ft_push_init(t_stack **s, int data, int index);

void	ft_indexing(t_stack *sorted_index, t_data *d);
void	ft_solve_5(t_data *d);
void	ft_stack_sort(t_stack **head);
void	ft_solve(t_data *d, int group);

void	ft_rotator(t_data *d, int ra, int rb);
void	ft_push_back_to_a(t_data *d);

int		ft_free_data(t_data *d);

int		ft_biggest_loop(t_stack *start, int set);
int		ft_distance_to_top(t_stack *a, int index);
int		ft_distance_to_index(int index, int size);
t_stack	*ft_nearest_in_group(t_stack *s, int group, int group_size);
t_stack	*ft_get_last(t_stack *s);
int		ft_stacklen(t_stack *s);
int		ft_has_index(t_stack *s, int index);
int		ft_is_sort(t_data *d);

void	ft_sa(t_data *d);
void	ft_sb(t_data *d);
void	ft_ss(t_data *d);
void	ft_pa(t_data *d);
void	ft_pb(t_data *d);
void	ft_ra(t_data *d);
void	ft_rb(t_data *d);
void	ft_rr(t_data *d);
void	ft_rra(t_data *d);
void	ft_rrb(t_data *d);
void	ft_rrr(t_data *d);

int		ft_is_int(char *str);
int		ft_isint_s(const char *str, int bool);
int		ft_isnum_s(char *str, int base);
int		ft_isspace_s(int c);

void	ft_exit(char *text);
int		ft_error(char *text);
long	ft_atol(char *str);
int		ft_max(int x, int y);
int		ft_min(int x, int y);
int		ft_abs(int a);

#endif

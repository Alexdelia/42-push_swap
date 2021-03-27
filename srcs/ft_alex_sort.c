/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 00:31:33 by adelille          #+#    #+#             */
/*   Updated: 2021/03/27 02:00:10 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_lst_average(t_list *lst)
{
	int	sum;
	int	i;

	sum = 0;
	i = 0;
	while (lst)
	{
		sum += lst->data;
		i++;
		lst = lst->next;
	}
	return (sum / i);
}

int	ft_is_sep(t_arg arg, int average)
{
	while (arg.a)
	{
		if (arg.a < average)
			return (FALSE);
		arg.a = arg.a->next;
	}
	while (arg.b)
	{
		if (arg.b >= average)
			return (FALSE);
	}
	return (TRUE);
}

int	ft_separate(t_arg *arg, int v)
{
	int	i;
	int	size;
	int	average;

	i = 0;
	size = ft_lst_size(arg->a);
	average = ft_lst_average(arg->a);
	while (i <= size && ft_sep(*arg, average) == FALSE)
	{
		if (arg->a->data > average)
		{
			ft_op_r(&arg->a);
			if (v == TRUE)
				ft_ps("ra\n");
		}
		else
		{
			ft_op_p(&arg->b, &arg->a);
			if (v == TRUE)
				ft_ps("pb\n");
		}
		i++;
	}
	return (i);
}

int	ft_smallest(t_list *lst)
{
	int smallest;

	smallest = INT_MAX;
	while (lst)
	{
		if (lst->data < smallest)
			smallest = lst->data;
		lst = lst->next
	}
	return (smallest);
}

int	ft_biggest(t_list *lst)
{
	int	biggest;

	biggest = INT_MIN;
	while (lst)
	{
		if (lst->data > biggest)
			biggest = lst->data;
		lst = lst->next;
	}
	return (biggest);
}

int	ft_next_small(t_list *lst, int last_small)
{
	int small;

	small = INT_MAX;
	while (lst)
	{
		if (lst->data < small && lst->data > last_small)
			small = lst->data;
		lst = lst->next
	}
	return (small);
}

int ft_next_big(t_list *lst, int last_big)
{
	int big;

	big = INT_MIN;
	while (lst)
	{
		if (lst->data < big && lst->data > last_big)
			big = lst->data;
		lst = lst->next
	}
	return (big);
}

int	ft_lst_last(t_list *lst, int data)
{
	while (lst && lst->next)
	{
		if (lst->data == data)
			return (FALSE);
		lst = lst->next;
	}
	if (lst->data == data)
		return (TRUE);
	return (FALSE);
}

int	ft_r_to_bot(t_arg *arg, int SmA, int BiB, int v)
{
	int	n_command;

	n_command = 0;
	while (ft_lst_last(arg->a, SmA) == FALSE && ft_lst_last(arg->b, BiB) == FALSE)
	{
		n_command += ft_need_ss(arg, v);
		if (ft_lst_last(arg->a, SmA) == TRUE)
		{
			ft_op_r(&arg->b);
			if (v == TRUE)
				ft_ps("rb\n");
			n_command++;
		}
		else if (ft_lst_last(arg->b, BiB) == TRUE)
		{
			ft_op_r(&arg->a);
			if (v == TRUE)
				ft_ps("ra\n");
			n_command++;
		}
		else
		{
			ft_op_r(&arg->a);
			ft_op_r(&arg->b);
			if (v == TRUE)
				ft_ps("rr\n");
			n_command++;
		}
	}
	return (n_command);
}

int	ft_find_close(t_list *lst, int data)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lst_size(lst);
	while (lst && lst->data != data)
	{
		i++;
		lst = lst->next;
	}
	return ((i > size / 2 ? 1 : -1));
}

int	ft_opti_shared_r(t_list **lst, int v, char *type)
{
	ft_op_r(lst);
	if (v == TRUE)
	{
		ft_ps("r");
		ft_ps(type);
	}
	return (1);
}

int	ft_opti_shared_rr(t_list **lst, int v, char *type)
{
	ft_op_rr(lst);
	if (v == TRUE)
	{
		ft_ps("rr");
		ft_ps(type);
	}
	return (1);
}

int	ft_opti_top(t_list **lst, int data, int v, char *type)
{
	int	n_command;

	n_command = 0;
	if (ft_find_close(*lst, data) == 1)
	{
		while (*(lst)->data != data)
			n_command += ft_opti_shared_r(lst, v, type);
		return (n_command);
	}
	while (*(lst)->data != data)
		n_command += ft_opti_shared_rr(lst, v, type);
	return (n_command)
}

int	ft_opti_bot(t_list **lst, int data, int v, char *type)
{
	int	n_command;

	n_command = 0;
	if (ft_find_close(*lst, data) == 1)
	{
		while (ft_lst_last(*lst, data) == FALSE)
			n_command += ft_opti_shared_r(lst, v, type);
		return (n_command);
	}
	while (ft_lst_last(*lst, data) == FALSE)
		n_command += ft_opti_shared_rr(lst, v, type);
	return (n_command)
}

int	ft_need_ss(t_arg *arg, int v)
{
	if (arg->a && arg->a->next && arg->a->data > arg->a->next->data
			&& arg->b &arg->b->next && arg->b->data < arg->b->next->data)
	{
		ft_op_sa(arg);
		ft_op_sb(arg);
		if (v == TRUE)
			ft_ps("ss\n");
		return (1);
	}
	return (0);
}

int	ft_alex_sort(t_arg arg, int v)
{
	int	n_command;
	int	next_big;
	int	next_small;

	n_command = ft_separate(&arg, v);
	next_big = ft_biggest(arg.b);
	next_small = ft_smallest(arg.a);
	n_command += ft_r_to_bot(&arg, next_small, next_big, v);
	while (ft_check_sort(arg.b) == FALSE && ft_check_unsort(arg.a) == FALSE)
	{
		n_command += ft_need_ss(&arg, v);
		if (ft_chek_sort(arg.b) == FALSE && ft_check_unsort(arg.b) == FALSE)
		{
			next_big = ft_next_big(arg.b, next_big);
			n_command += ft_opti_top(&arg.b, next_big, v, "b\n");
			ft_op_p(&arg.b, &arg.a);
			if (v == TRUE)
				ft_ps("pb\n");
			n_command++;
		}
	}
}

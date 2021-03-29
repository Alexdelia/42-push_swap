/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_separate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 02:04:47 by adelille          #+#    #+#             */
/*   Updated: 2021/03/29 11:20:40 by adelille         ###   ########.fr       */
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

int	ft_brute_force_median(t_list *lst)
{
	t_list	*head;
	t_list	*i;
	int		med;

	i = lst;
	while (i)
	{
		med = 0;
		head = lst;
		while (head != NULL)
		{
			if (i->data > head->data)
				med = med + 1;
			if (i->data < head->data)
				med = med - 1;
			head = head->next;
		}
		if (med == 0 || med == 1 || med == -1)
			return (i->data);
		i = i->next;
	}
	return (0);
}

int	ft_security(t_arg *arg)
{
	int	n_command;

	n_command = ft_opti_top(&arg->a, ft_smallest(arg->a), TRUE, "a\n");
	ft_op_p(&arg->b, &arg->a);
	ft_ps("pb\n");
	return (n_command + 1);
}

int	ft_advance_separate_loop(t_arg *arg, int average)
{
	if (arg->a->data < average)
	{
		ft_op_p(&arg->b, &arg->a);
		ft_ps("pb\n");
		return (1);
	}
	else if (ft_lst_last(arg->a) < average)
	{
		ft_op_rr(&arg->a);
		ft_op_p(&arg->b, &arg->a);
		ft_ps("rra\npb\n");
		return (2);
	}
	if (ft_lstsize(arg->a) == 3)
		return (ft_security(arg));
	ft_op_r(&arg->a);
	ft_ps("ra\n");
	return (1);
}

int	ft_advance_separate(t_arg *arg)
{
	int	n_command;
	int	old_size_b;
	int	size;
	int	median;

	n_command = 0;
	old_size_b = ft_lstsize(arg->b);
	size = ft_lstsize(arg->a);
	median = ft_brute_force_median(arg->a);
	while (ft_lstsize(arg->a) > 2 
			/*&& (ft_lstsize(arg->b) - old_size_b) < (size + 1) / 2*/
			&& ft_lst_under_exist(arg->a, median) == TRUE)
		n_command += ft_advance_separate_loop(arg, median);
	if (old_size_b == 0)
		arg->chunk = ft_lstnew(ft_lstsize(arg->b));
	else
		ft_lstadd_back(&arg->chunk, ft_lstnew(ft_lstsize(arg->b) - old_size_b));
	return (n_command);
}

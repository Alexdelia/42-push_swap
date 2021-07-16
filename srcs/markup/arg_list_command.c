/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_list_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 23:25:38 by adelille          #+#    #+#             */
/*   Updated: 2021/07/16 23:33:06 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_arg	*ft_create_command(const char *name)
{
	t_arg	*arg;

	arg = (t_arg *)ft_memalloc(sizeof(t_arg));
	if (!arg)
		ft_exit("Error: Malloc failed in ft_create_command\n");
	arg->name = ft_strdup(name);
	arg->next = NULL;
	return (arg);
}

void	ft_add_command(t_arg_list *arg_list, t_arg *arg)
{
	t_arg	*last;

	if (arg_list && arg)
	{
		if (!arg_list->head)
			arg_list->head = arg;
		else
		{
			last = arg_list->head;
			while (last-next)
				last = last->next;
			last->next = arg;
		}
		arg_list->size++;
	}
}

void	ft_print_commands(t_arg_list *arg_list)
{
	t_arg	*current;

	current = arg_list->head;
	while (current)
	{
		ft_ps(current->name);
		current = current->next;
		// might free here
	}
}

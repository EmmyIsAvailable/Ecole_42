/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:05:10 by eruellan          #+#    #+#             */
/*   Updated: 2022/01/28 14:20:40 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lst_add_back(t_stack *front, t_stack *new)
{
	t_stack	*tmp;

	if (!front)
		front = new;
	else
	{
		tmp = front;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
		new->next = NULL;
	}
	return (front);
}

void	ft_lstdel(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
}

t_stack	*ft_fill_stack(t_var *arg)
{
	int	i;
	t_stack	*new;

	arg->a = NULL;
	i = -1;
	while (arg->tab[++i])
	{
		new = (t_stack *)malloc(sizeof(t_stack));
		if (!new)
		{
			ft_lstdel(arg->a);
			return (0);
		}
		new->val = ft_atoi(arg->tab[i]);
		new->next = NULL;
		new->prev = NULL;
		arg->a = ft_lst_add_back(arg->a, new);
		new = NULL;
	}
	return (arg->a);
}

int	ft_size_stack(t_stack *a)
{
	int	i;
	t_stack	*tmp;

	i = 0;
	tmp = a;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	is_in_tab(t_var *arg)
{
	int	i;

	i = 0;
	while (arg->tab[i])
	{
		if (ft_atoi(arg->tab[i]) == arg->b->val)
			return (1);
		i++;
	}
	return (0);
}

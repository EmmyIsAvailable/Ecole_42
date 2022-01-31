/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationbis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:22:24 by eruellan          #+#    #+#             */
/*   Updated: 2022/01/31 12:11:21 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*t_stack	*ft_push(t_stack *a, t_stack *b)
{
	int	inter;
	t_stack	*new;

	if (b)
	{
		inter = b->val;
		new = (t_stack *)malloc(sizeof(t_stack));
		if (!new)
			return (NULL);
		new->val = inter;
		new->prev = NULL;
		if (a)
		{		
			new->next = a;
			a->prev = new;
		}
		else
			new->next = NULL;
	}
	return (new);
}*/

t_stack	*ft_push(t_stack *a, t_stack *b)
{
	t_stack	*tmp;
	t_stack	*from;
	t_stack	*to;
	
	if (b)
	{
		from = b;
		to = a;
		tmp = from;
		if (!to)
		{
			to = tmp;
			to->next = NULL;
			a = to;
		}
		else
		{
			tmp->next = to;
			to->prev = tmp;
			a = tmp;
		}
	}
	return (a);
}

t_stack	*ft_swap(t_stack *a)
{
	t_stack	*tmp;
	int	val_inter;

	if (a && a->next)
	{
		tmp = a;
		val_inter = tmp->val;
		tmp->val = tmp->next->val;
		a->next->val = val_inter;
	}
	return (a);
}

/*t_stack	*ft_reverse(t_stack *a)
{
	t_stack	*tmp;
	int	last;
	t_stack	*new;

	if (a && a->next)
	{
		tmp = a;
		while (tmp->next)
			tmp = tmp->next;
		last = tmp->val;
		tmp = tmp->prev;
		free(tmp->next);
		tmp->next = NULL;
		new = (t_stack *)malloc(sizeof(t_stack));
		if (!new)
			return (NULL);
		new->val = last;
		new->next = a;
		new->prev = NULL;
		a->prev = new;
	}
	return (new);
}*/

t_stack	*ft_reverse(t_stack *a)
{
	t_stack	*tmp;
	int	last;

	if (a && a->next)
	{
		tmp = a;
		while (tmp->next)
			tmp = tmp->next;
		last = tmp->val;
		while (tmp->prev)
		{
			tmp->val = tmp->prev->val;
			tmp = tmp->prev;
		}
		tmp->val = last;
	}
	return (a);
}

/*t_stack	*ft_rotate(t_stack *a)
{
	t_stack	*tmp;
	int	first;
	t_stack	*new;

	if (a && a->next)
	{
		tmp = a;
		first = tmp->val;
		while (tmp && tmp->next)
			tmp = tmp->next;
		new = (t_stack *)malloc(sizeof(t_stack));
		if (!new)
			return (NULL);
		new->val = first;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
		a = a->next;
	}
	return (a);
}*/

t_stack	*ft_rotate(t_stack *a)
{
	t_stack	*tmp;
	int	first;

	if (a && a->next)
	{
		tmp = a;
		first = tmp->val;
		while (tmp->next)
		{
			tmp->val = tmp->next->val;
			tmp = tmp->next;
		}
		tmp->val = first;
	}
	return (a);
}

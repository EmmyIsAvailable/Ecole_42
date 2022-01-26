/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:20:55 by eruellan          #+#    #+#             */
/*   Updated: 2022/01/26 19:20:57 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3_a(t_var *arg)
{
	int	i;

	i = 0;
	if (arg->a->val < arg->a->next->val)
	{
		if (arg->a->val < arg->a->next->next->val)
			i = 1;
		ft_choice(arg, 9);
		if (i)
			ft_choice(arg, 1);
	}
	else
	{
		if (arg->a->val < arg->a->next->next->val)
			ft_choice(arg, 1);
		else
		{
			if (arg->a->next->val > arg->a->next->next->val)
				i = 1;
			ft_choice(arg, 6);
			if (i)
				ft_choice(arg, 1);
		}
	}
}

void	ft_sort_2_a(t_var *arg)
{
	if (arg->a->val > arg->a->next->val)
		ft_choice(arg, 1);
}

void	ft_reverse_a(t_var *arg, int *r)
{
	int	len;

	len = ft_size_stack(arg->a);
	if (*r > (len / 2) && len > 3)
	{
		while (*r < len)
		{
			ft_choice(arg, 6);
			*r = *r + 1;
		}
	}
	else if (len > 3)
	{
		while (*r)
		{
			ft_choice(arg, 9);
			*r = *r -1;
		}
	}
}

t_stack	*ft_sort_a(t_var *arg, int len)
{
	int	p;
	int	r;

	p = 0;
	r = 0;
	if (arg->a && check_sorted_a(arg) == 0)
		return (arg->a);
	if (len <= 3)
	{
		if (ft_size_stack(arg->a) == 3)
			ft_sort_3_a(arg);
		else
			ft_sort_short_a(arg, arg->a);
		return(arg->a);
	}
	ft_median_sorted_a(arg, &r, &p, len);
	ft_reverse_a(arg, &r);
	arg->a = ft_sort_a(arg, (len - p));
	arg->b = ft_sort_b(arg, p);
	while (p-- && arg->b)
		ft_choice(arg, 4);
	return (arg->a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:21:05 by eruellan          #+#    #+#             */
/*   Updated: 2022/01/31 12:21:13 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3_b(t_var *arg)
{
	int	i;

	i = 0;
	if (arg->b->val > arg->b->next->val)
	{
		if (arg->b->val > arg->b->next->next->val)
			i = 1;
		ft_choice(arg, 10);
		if (i)
			ft_choice(arg, 2);
	}
	else
	{
		if (arg->b->val > arg->b->next->next->val)
			ft_choice(arg, 2);
		else
		{
			if (arg->b->next->val < arg->b->next->next->val)
				i = 1;
			ft_choice(arg, 7);
			if (i)
				ft_choice(arg, 2);
		}
	}
}

void	ft_sort_2_b(t_var *arg)
{
	if (arg->b->val < arg->b->next->val)
		ft_choice(arg, 2);
}

void	ft_reverse_b(t_var *arg, int *r)
{
	int	len;

	len = ft_size_stack(arg->b);
	if (*r > (len / 2) && len > 3)
	{
		while (*r < len)
		{
			ft_choice(arg, 7);
			*r += 1;
		}
	}
	else if (len > 3)
	{
		while (*r)
		{
			ft_choice(arg, 10);
			*r -= 1;
		}
	}
}

t_stack	*ft_sort_b(t_var *arg, int len)
{
	int	p;
	int	r;

	p = 0;
	r = 0;
	if (len <= 3)
	{
		ft_sort_short_b(arg, arg->b);
		return (arg->b);
	}
	ft_median_sorted_b(arg, &r, &p, len);
	arg->a = ft_sort_a(arg, p);
	ft_reverse_b(arg, &r);
	arg->b = ft_sort_b(arg, (len - p));
	if (arg->b && check_sorted_b(arg) == 1)
	{
		while (p--)
			ft_choice(arg, 5);
	}
	return (arg->b);
}

int    ft_median_sorted_b(t_var *arg, int *r, int *p, int len)
{
        int     median;
        t_stack *tmp;
        int     i;

        median = ft_find_median(arg->b, 2, len);
        i = 0;
        while (i < len && while_above_median(arg, len - i, median))
        {
                if (arg->b->val > median)
                {
                        *p += 1;
                        tmp = arg->b->next;
			ft_choice(arg, 4);
			arg->b = tmp;
			if (tmp)
				arg->b->prev = NULL;
                }
                else
                {
                        *r += 1;
                        ft_choice(arg, 7);
                }
                i++;
        }
	return (*p);
}

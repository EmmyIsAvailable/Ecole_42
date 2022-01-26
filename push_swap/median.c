/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:20:41 by eruellan          #+#    #+#             */
/*   Updated: 2022/01/26 19:20:42 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_sort_tab(int *tab, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - 1)
		{
			if (tab[j] < tab[i])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

int	ft_find_median(t_stack *a, int stack, int len)
{
	int	i;
	int	median;
	int	*tab;
	t_stack	*tmp;

	i = -1;
	tmp = a;
	tab = (int *)malloc(sizeof(int) * len);
	if (!tab)
		return (0);
	while (++i < len)
	{
		tab[i] = tmp->val;
		tmp = tmp->next;
	}
	tab = ft_sort_tab(tab, len);
	if (len % 2 == 0 && stack == 2)
		median = tab[(len / 2) - 1];
	else
		median = tab[len / 2];
	free(tab);
	return (median);
}

int	ft_median_sorted_a(t_var *arg, int *r, int *p, int len)
{
	int	median;
	t_stack	*tmp;
	int	i;
	//int	size;

	median = ft_find_median(arg->a, 1, len);
	tmp = arg->a;
	i = 0;
	//size = ft_size_stack(arg->a);
	while (i < len && while_under_median(arg, len - i, median))
	{
		if (tmp->val < median)
		{
			*p = *p + 1;
			ft_choice(arg, 5);
		}
		else
		{
			*r = *r + 1;
			ft_choice(arg, 6);
		}
		tmp = tmp->next;
		i++;
	}
	return (*p);
}

int	while_under_median(t_var *arg, int n, int median)
{
	int	i;
	t_stack	*tmp;

	i = 0;
	tmp = arg->a;
	while (i < n)
	{
		if (tmp->val < median)
			return (1);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

int	while_above_median(t_var *arg, int n, int median)
{
	int	i;
	t_stack	*tmp;

	i = 0;
	tmp = arg->b;
	while (i < n)
	{
		if (tmp->val > median)
			return (1);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

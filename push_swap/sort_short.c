/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:21:15 by eruellan          #+#    #+#             */
/*   Updated: 2022/01/26 19:21:17 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_short_a(t_var *arg, t_stack *a)
{
	int	len;

	len = ft_size_stack(a);
	if (len >= 2 && a->val > a->next->val)
		ft_choice(arg, 1);
	if (len >= 3 && a->next->val > a->next->next->val)
		{
			ft_choice(arg, 6);
			ft_choice(arg, 1);
			ft_choice(arg, 9);
		}
	if (len >= 2 && a->val > a->next->val)
			ft_choice(arg, 1);
}

void	ft_sort_short_b(t_var *arg, t_stack *b)
{
	int	len;

	len = ft_size_stack(b);
	if (len >= 2 && b->val < b->next->val)
		ft_choice(arg, 2);
	if (len >= 3 && b->next->val < b->next->next->val)
		{
			ft_choice(arg, 7);
			ft_choice(arg, 2);
			ft_choice(arg, 10);
		}
	if (len >= 2 && b->val < b->next->val)
			ft_choice(arg, 2);
}

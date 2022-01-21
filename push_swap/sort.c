#include "push_swap.h"

void	ft_sort_3(t_var *arg)
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

void	ft_sort_2(t_var *arg)
{
	if (arg->a->val > arg->a->next->val)
		ft_choice(arg, 1);
}

void	ft_sort(t_var *arg, int len)
{
	int	p;
	int	r;

	p = 0;
	r = 0;
	if (len == 2)
		ft_sort_2(arg);
	else if (len == 3)
		ft_sort_3(arg);
	else
	{
		ft_median_sorted(arg, &r, &p);
		ft_sort(arg, (len - p));
	}
}

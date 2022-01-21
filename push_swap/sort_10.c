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

#include "push_swap.h"

void	ft_sort_short_a(t_var *arg)
{
	if (check_sorted_a(arg))
	{
		if (arg->a->val > arg->a->next->val)
		{
			ft_choice(arg, 1);
			if (arg->a->next->val > arg->a->next->next->val)
			{
				ft_choice(arg, 6);
				ft_choice(arg, 1);
				ft_choice(arg, 9);
			}
			if (arg->a->val > arg->a->next->val)
				ft_choice(arg, 1);
		}
		else
		{
			ft_choice(arg, 6);
			ft_choice(arg, 1);
			ft_choice(arg, 9);
			if (arg->a->val > arg->a->next->val)
				ft_choice(arg, 1);
		}
	}
}

void	ft_sort_short_b(t_var *arg)
{
	printf("non");
	if (check_sorted_b(arg))
	{
		printf("oui");
		if(arg->b->val < arg->b->next->val)
		{
			ft_choice(arg, 2);
			if (arg->b->next->val < arg->b->next->next->val)
			{
				ft_choice(arg, 7);
				ft_choice(arg, 2);
				ft_choice(arg, 10);
			}
			if (arg->b->val < arg->b->next->val)
				ft_choice(arg, 2);
		}
		else
		{
			ft_choice(arg, 7);
			ft_choice(arg, 2);
			ft_choice(arg, 10);
			if (arg->b->val < arg->b->next->val)
				ft_choice(arg, 2);
		}
	}
}

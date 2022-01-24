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

void	ft_sort_a(t_var *arg, int len)
{
	int	p;
	int	r;

	p = 0;
	r = 0;
	printf("sort a, lena : %d\n", len);
	t_stack *tmp = arg->a;
	t_stack *tmpb = arg->b;
	while (tmp)
	{
		printf("a : %d\n", tmp->val);
		tmp = tmp->next;	
	}
	while (tmpb)
	{
		printf("b : %d\n", tmpb->val);
		tmpb = tmpb->next;
	}
	if (len <= 1)
		return ;
	if (len == 2)
	{
		ft_sort_2_a(arg);
		return ;
	}
	else if (len == 3)
	{
		if (ft_size_stack(arg->a) == 3)
			ft_sort_3_a(arg);
		else
			ft_sort_short_a(arg);
		return ;
	}
	if (arg->a && !arg->b && check_sorted_a(arg) == 0)
		return ;
	ft_median_sorted_a(arg, &r, &p);
	printf("dans a -> p : %d, r : %d\n", p, r);
	ft_sort_a(arg, (len - p));
	ft_sort_b(arg, p);
	while (p-- && arg->b)
		ft_choice(arg, 4);
}

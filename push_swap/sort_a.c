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

t_stack	*ft_sort_a(t_var *arg, int len)
{
	int	p;
	int	r;

	p = 0;
	r = 0;
	printf("sort a, lena : %d\n", len);
	if (len <= 3)
	{
		t_stack *tmpa1 = arg->a;
		while (tmpa1)
		{
			printf("sort a len 3 : %d\n", tmpa1->val);
			tmpa1 = tmpa1->next;
		}
		ft_sort_short_a(arg, arg->a);
		return(arg->a);
	}
	if (arg->a && !arg->b && check_sorted_a(arg) == 0)
		return (arg->a);
	ft_median_sorted_a(arg, &r, &p);
	printf("dans a -> p : %d, r : %d\n", p, r);
	arg->a = ft_sort_a(arg, (len - p));
	arg->b = ft_sort_b(arg, p);
	while (p-- && arg->b)
		ft_choice(arg, 4);
	return (arg->a);
}

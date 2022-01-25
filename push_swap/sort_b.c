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

t_stack	*ft_sort_b(t_var *arg, int len)
{
	int	p;
	int	r;

	p = 0;
	r = 0;
	printf("sort b, len %d, p : %d\n", len, p);
	t_stack *tmpb = arg->b;
	t_stack *tmpa = arg->a;
	while (tmpa)
	{
		printf("sort b, a : %d\n", tmpa->val);
		tmpa = tmpa->next;
	}
	while (tmpb)
	{
		printf("sort b, b : %d\n", tmpb->val);
		tmpb = tmpb->next;
	}
	if (len <= 3)
	{
		printf("len de 3\n");	
		ft_sort_short_b(arg, arg->b);
		return (arg->b);
	}
	ft_median_sorted_b(arg, &r, &p, len);
	printf("dans b -> p : %d, r -> %d\n", p, r);
	arg->a = ft_sort_a(arg, p);
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
        int     size;

        median = ft_find_median(arg->b, 2, len);
        tmp = arg->b;
        i = 0;
        size = ft_size_stack(arg->b);
        while (i < size)
        {
                if (tmp->val > median)
                {
                        *p += 1;
                        ft_choice(arg, 4);
                }
                else
                {
                        *r += 1;
                        ft_choice(arg, 7);
                }
                tmp = tmp->next;
                i++;
        }
	return (*p);
}

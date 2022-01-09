#include "push_swap.h"

void	ft_choice3(t_var *arg, int a)
{
	if (a == 10)
	{
		ft_putstr_fd("rrb\n", 1);
		ft_reverse(arg->b);
	}
	if (a == 11)
	{
		ft_putstr_fd("rrr\n", 1);
		ft_reverse(arg->a);
		ft_reverse(arg->b);
	}
}

void	ft_choice2(t_var *arg, int a)
{
	if (a == 5)
	{
		ft_putstr_fd("pb\n", 1);
		ft_push(arg->b, arg->a);
	}
	if (a == 6)
	{
		ft_putstr_fd("ra\n", 1);
		ft_rotate(arg->a);
	}
	if (a == 7)
	{
		ft_putstr_fd("rb\n", 1);
		ft_rotate(arg->b);
	}
	if (a == 8)
	{
		ft_putstr_fd("rr\n", 1);
		ft_rotate(arg->a);
		ft_rotate(arg->b);
	}
	if (a == 9)
	{
		ft_putstr_fd("rra\n", 1);
		ft_reverse(arg->a);
	}
	else
		ft_choice3(arg, a);
}

void	ft_choice(t_var *arg, int a)
{
	if (a == 1)
	{
		ft_putstr_fd("sa\n", 1);
		ft_swap(arg->a);
	}
	if (a == 2)
	{
		ft_putstr_fd("sb\n", 1);
		ft_swap(arg->b);
	}
	if (a == 3)
	{
		ft_putstr_fd("ss\n", 1);
		ft_swap(arg->a);
		ft_swap(arg->b);
	}
	if (a == 4)
	{
		ft_putstr_fd("pa\n", 1);
		ft_push(arg->a, arg->b);
	}
	else
		ft_choice2(arg, a);
}

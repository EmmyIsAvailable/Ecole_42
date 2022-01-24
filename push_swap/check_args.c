#include "push_swap.h"

int	check_doubles(t_var *arg)
{
	int	i;
	int	j;

	i = -1;
	while (arg->tab[++i])
	{
		j = i;
		while (arg->tab[++j])
		{
			if (ft_strncmp(arg->tab[i], arg->tab[j], 11) == 0)
				ft_error("Error : double values\n", 1);
		}
	}
	return (1);
}

int	check_overflow(char *nb)
{
	long long	n;

	n = ft_atoll(nb);
	if (n >= INT_MIN && n <= INT_MAX && ft_strlen(nb) < 12)
		return (1);
	return (0);
}

int	check_numbers(t_var *arg)
{
	int	i;
	int	j;

	i = -1;
	if (!arg->tab[0])
		ft_error("Error : no number entered\n", 1);
	while (arg->tab[++i])
	{
		if (!check_overflow(arg->tab[i]))
			ft_error("Error : int overflow\n", 1);
		j = -1;
		while (arg->tab[i][++j])
		{
			if (!ft_is_in_scope(arg->tab[i][j]) || (arg->tab[i][j] == '-' && !ft_isdigit(arg->tab[i][j + 1]))
				|| (arg->tab[i][j] == '+' && !ft_isdigit(arg->tab[i][j + 1])))
				ft_error("Error : invalid arguments\n", 1);
		}
	}
	return (1);
}

int	check_sorted_a(t_var *arg)
{
	t_stack	*tmp;

	tmp = arg->a;
	while (tmp && tmp->next)
	{
		if (tmp->val < tmp->next->val)
			tmp = tmp->next;
		else
			return (1);	
	}
	return (0);
}

int	check_sorted_b(t_var *arg)
{
	t_stack	*tmp;

	tmp = arg->b;
	while (tmp && tmp->next)
	{
		if (tmp->val > tmp->next->val)
			tmp = tmp->next;
		else
			return (1);	
	}
	return (0);
}

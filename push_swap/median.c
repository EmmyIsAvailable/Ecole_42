#include "push_swap.h"

int	*ft_sort_tab(int *tab)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
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

int	ft_find_median(t_stack *a)
{
	int	i;
	int	median;
	int	*tab;
	t_stack	*tmp;

	i = 0;
	tmp = a;
	tab = (int *)malloc(sizeof(int) * ft_size_stack(tmp) + 1);
	if (!tab)
		return (0);
	while (tmp)
	{
		tab[i++] = tmp->val;
		tmp = tmp->next;
	}
	tab = ft_sort_tab(tab);
	if (i % 2 == 0)
		median = tab[i / 2];
	else
		median = tab[(i + 1) / 2];
	free(tab);
	return (median);
}

void	ft_median_sorted(t_var *arg)
{
	int	median;
	t_stack	*tmp;
	int	i;
	int	size;

	median = ft_find_median(arg->a);
	tmp = arg->a;
	i = 0;
	size = ft_size_stack(arg->a);
	while (i < size)
	{
		if (tmp->val < median)
			ft_choice(arg, 4);
		else
			ft_choice(arg, 6);
		tmp = tmp->next;
		i++;
	}
}

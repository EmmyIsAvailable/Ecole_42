#include "push_swap.h"

int	*ft_sort_tab(int *tab, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - 1)
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

int	ft_find_median(t_stack *a, int stack, int len)
{
	int	i;
	int	median;
	int	*tab;
	t_stack	*tmp;

	i = -1;
	tmp = a;
	tab = (int *)malloc(sizeof(int) * len);
	if (!tab)
		return (0);
	while (++i < len)
	{
		tab[i] = tmp->val;
		tmp = tmp->next;
	}
	tab = ft_sort_tab(tab, len);
	int j = -1;
	while (++j < len)
		printf("tab %d\n", tab[j]);
	if (len % 2 == 0 && stack == 2)
		median = tab[(len / 2) - 1];
	else
		median = tab[(len / 2)];
	printf("median : %d, stack %d\n", median, stack);
	free(tab);
	return (median);
}

int	ft_median_sorted_a(t_var *arg, int *r, int *p, int len)
{
	int	median;
	t_stack	*tmp;
	int	i;
	int	size;

	median = ft_find_median(arg->a, 1, len);
	printf("median %d\n", median);
	tmp = arg->a;
	i = 0;
	size = ft_size_stack(arg->a);
	while (i < size)
	{
		if (tmp->val < median)
		{
			*p += 1;
			ft_choice(arg, 5);
		}
		else
		{
			*r += 1;
			ft_choice(arg, 6);
		}
		tmp = tmp->next;
		i++;
	}
	return (*p);
}

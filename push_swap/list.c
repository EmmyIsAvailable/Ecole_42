#include "push_swap.h"

void	ft_lst_add_back(t_stack **front, t_stack *new)
{
	t_stack	*tmp;

	if (!(*front))
		*front = new;
	else
	{
		tmp = *front;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}


t_stack	*ft_fill_stack(t_var *arg)
{
	int	i;
	t_stack	*new;

	i = -1;
	while (arg->tab[++i])
	{	
		new = (t_stack *)malloc(sizeof(t_stack));
		if (!new)
			return (NULL);
		new->val = ft_atoi(arg->tab[i]);
		new->next = NULL;
		new->prev = NULL;
		ft_lst_add_back(&arg->a, new);
		//free stack new
		new = NULL;
	}
	return (arg->a);
}

int	ft_size_stack(t_var *arg)
{
	int	i;
	t_stack	*tmp;

	i = 0;
	tmp = arg->a;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

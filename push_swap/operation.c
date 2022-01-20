#include "push_swap.h"

t_stack	*ft_push(t_stack *a, t_stack *b)
{
	t_stack	*tmp;

	if (a && b)
	{
		tmp = b;
		a->prev = tmp;
		tmp->next = a;
		tmp->prev = NULL;
		b = b->next;
	}
	return (a);
}

t_stack	*ft_swap(t_stack *a)
{
	t_stack	*tmp;
	int	val_inter;

	if (a && a->next)
	{
		tmp = a;
		val_inter = tmp->val;
		tmp->val = tmp->next->val;
		a->next->val = val_inter;
	}
	return (a);
}

t_stack	*ft_reverse(t_stack *a)
{
	t_stack	*tmp;
	int	last;
	t_stack	*new;

	if (a && a->next)
	{
		tmp = a;
		while (tmp->next && tmp->next->next)
			tmp = tmp->next;
		last = tmp->next->val;
		tmp->next = NULL;
		while (tmp && tmp->prev)
			tmp = tmp->prev;
		new = (t_stack *)malloc(sizeof(t_stack));
		if (!new)
			return (NULL);
		new->val = last;
		new->next = tmp;
		new->prev = NULL;
		tmp->prev = new;
	}
	return (new);
}

t_stack	*ft_rotate(t_stack *a)
{
	t_stack	*tmp;
	int	first;
	t_stack	*new;

	if (a && a->next)
	{
		tmp = a;
		first = tmp->val;
		while (tmp && tmp->next)
			tmp = tmp->next;
		new = (t_stack *)malloc(sizeof(t_stack));
		if (!new)
			return (NULL);
		new->val = first;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
		a = a->next;
	}
	return (a);
}

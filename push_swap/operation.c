#include "push_swap.h"

void	ft_push(t_stack *a, t_stack *b)
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
}

t_stack	*ft_swap(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (a && a->next)
	{
		if (a->next->next)
			tmp2 = a->next->next;
		tmp = a->next;
		if (tmp2)
			a->next = tmp2;
		else
			a->next = NULL;
		a->prev = tmp;
		tmp->next = a;
		tmp->prev = NULL;
	}
	return (tmp);
}

void	ft_reverse(t_stack *a)
{
	t_stack	*first;

	if (a && a->next)
	{
		first = a;
		while (a)
			a = a->next;
		a->next = first;
		first->next = NULL;
		first->prev = a;
	}
}

void	ft_rotate(t_stack *a)
{
	t_stack	*end;
	if (a && a->next)
	{
		end = a;
		while (end)
			end = end->next;
		a->prev = end;
		end->next = a;
		end->prev = NULL;
	}
}

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

void	ft_swap(t_stack *a)
{
	t_stack	*tmp;

	if (a && a->next)
	{
		tmp = a;
		a = a->next;
		a->prev = tmp;
		tmp->next = a;
		tmp->prev = NULL;
	}
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

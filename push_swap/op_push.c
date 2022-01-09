#include "push_swap.h"

void	ft_push(t_stack *a, t_stack *b)
{
	t_stack	*tmp;

	tmp = NULL;
	if (a && b)
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		tmp->val = b->val;
		tmp->next = b->next;
		tmp->prev = NULL;
		b = b->next;
		
	}
}

#include "push_swap.h"

void	ft_error(char *message, int error)
{
	if (error == 1)
		ft_putstr_fd(message, 2);
	exit(error);
}

t_var	ft_init(t_var *var)
{
	var = malloc(sizeof(t_var));
	if (!var)
		ft_error("Error : initialisation failed\n", 1);
	var->len = 0;
	var->b = NULL;
	var->tab = NULL;
	return (*var);
}

char	**fill_stack(t_var *arg, int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 2)
		arg->tab = ft_split(av[1], ' ');
	else
	{
		while (++i < ac)
			arg->tab[i - 1] = ft_strdup(av[i]);
		arg->tab[i - 1] = NULL;
	}
	return (arg->tab);
}

void	push_swap(t_var *arg)
{
	if (!check_doubles(arg) || !check_numbers(arg))
		ft_free_tab(arg->tab);
	arg->a = ft_fill_stack(arg);
	arg->len = ft_size_stack(arg->a);
	if (!check_sorted(arg))
		ft_error("Error : list of arguments already sorted\n", 1);
	ft_sort(arg, arg->len);
	t_stack *tmp = arg->a;
	while (tmp)
	{
		printf("a = %d\n", tmp->val);
		tmp = tmp->next;
	}
	t_stack *tmp2 = arg->b;
	while (tmp2)
	{
		printf("b = %d\n", tmp2->val);
		tmp2 = tmp2->next;
	}
	
}

int	main(int ac, char **av)
{
	t_var	arg;

	if (ac < 2)
		ft_error("Error : format is './push-swap <stack>'\n", 1);
	else
	{
		ft_init(&arg);
		if (!(arg.tab = fill_stack(&arg, ac, av)))
			ft_error("Error : splitting stack failed\n", 1);
		push_swap(&arg);
	}
	return (0);
}

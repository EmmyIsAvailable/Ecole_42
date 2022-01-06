#include "push_swap.h"

void	ft_error(char *message, int error)
{
	if (error == 1)
		ft_putstr_fd(message, 2);
	exit(error);
}

char	**fill_stack(t_var arg, int ac, char **av)
{
	if (ac == 2)
		arg->tab = ft_split(av, ' ');
	else
		arg->tab = &av[1];
	return (arg->tab);
}

void	push_swap(t_var *arg)
{
	check_doubles(arg);	
}

int	main(int ac, char **av)
{
	t_var	arg;

	if (ac < 2)
		ft_error("no argument entered", 1);
	else
	{
		arg.tab = fill_stack(arg, ac, av);
	}
	return (0);
}

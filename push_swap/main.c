/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:22:39 by eruellan          #+#    #+#             */
/*   Updated: 2022/01/31 17:59:16 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *message, int error, t_var *arg)
{
	if (arg->tab)
		ft_free_tab(arg->tab);
	if (arg->a)
		ft_lstdel(arg->a);
	if (error == 1)
		ft_putstr_fd(message, 2);
	exit(error);
}

t_var	ft_init(t_var *var, int ac, char **av)
{
	var->len = 0;
	var->p = 0;
	var->a = NULL;
	var->b = NULL;
	var->ac = ac;
	var->av = av;
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
		arg->tab = malloc(sizeof(char *) * ac);
		if (!arg->tab)
			return (NULL);
		while (++i < ac)
			arg->tab[i - 1] = ft_strdup(av[i]);
		arg->tab[i - 1] = NULL;
	}
	return (arg->tab);
}

void	push_swap(t_var *arg)
{
	if (!check_numbers(arg))
		return ;
	arg->a = ft_fill_stack(arg);
	arg->len = ft_size_stack(arg->a);
	if (!check_doubles(arg))
		return ;
	if (!check_sorted_a(arg))
		ft_error(NULL, 1, arg);
	if (arg->len == 2)
		ft_sort_2_a(arg);
	else if (arg->len == 3)
		ft_sort_3_a(arg);
	else
		ft_sort_a(arg, arg->len);
}

int	main(int ac, char **av)
{
	t_var	arg;

	if (ac < 2)
		return (0);
	else
	{
		ft_init(&arg, ac, av);
		arg.tab = fill_stack(&arg, ac, av);
		if (!arg.tab)
			ft_error("Error : filling tab failed\n", 1, &arg);
		push_swap(&arg);
		ft_free_tab(arg.tab);
		ft_lstdel(arg.a);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:22:39 by eruellan          #+#    #+#             */
/*   Updated: 2022/01/26 13:49:17 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	var->a = NULL;
	var->b = NULL;
	var->tab = NULL;
	var->p = 0;
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
	{
		ft_free_tab(arg->tab);
		//free var;
		return ;
	}
	arg->len = ft_fill_stack(arg);
	if (!check_sorted_a(arg))
		ft_error("Error : list of arguments already sorted\n", 1);
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
		ft_error("Error : format is './push-swap <stack>'\n", 1);
	else
	{
		ft_init(&arg);
		if (!(arg.tab = fill_stack(&arg, ac, av)))
			ft_error("Error : splitting stack failed\n", 1);
		
		push_swap(&arg);
		free(arg.a);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:22:53 by eruellan          #+#    #+#             */
/*   Updated: 2022/02/15 16:21:34 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

int	ft_init_mutex(t_data *data)
{
	int	i;

	i = data->nb_philos;
	while (i >= 0)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL) != 0)
			return (1);
		i--;
	}
	if (pthread_mutex_init(&(data->is_writing), NULL) != 0)
		return (1);
	if (pthread_mutex_init(&(data->check_death), NULL) != 0)
		return (1);
	if (pthread_mutex_init(&(data->meal_check), NULL) != 0)
		return (1);
	return (0);
}

int	ft_init_philo(t_data *data)
{
	int	i;

	i = data->nb_philos;
	while (i >= 0)
	{
		data->philosophers[i].forks = 0;
		data->philosophers[i].address = i;
		data->philosophers[i].lfork = 0;
		data->philosophers[i].rfork = 0;
		data->philosophers[i].left_fork_id = i;
		data->philosophers[i].right_fork_id = (i + 1) % data->nb_philos;
		data->philosophers[i].times_eaten = 0;
		data->philosophers[i].last_meal = 0;
		data->philosophers[i].data = data;
		i--;
	}
	return (0);
}

int	ft_init_data(t_data *data, char **av)
{
	data->nb_philos = ft_atoi(av[1]);
	data->time_death = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	data->death = 0;
	data->fed_up = 0;
	data->forks_bool = malloc(sizeof(char) * data->nb_philos);
	if (!data->forks_bool)
		return (1);
	memset(data->forks_bool, 1, data->nb_philos);
	if (data->nb_philos < 1 || data->nb_philos > 250
		|| data->time_death < 0 || data->time_eat < 0 || data->time_sleep < 0)
		return (1);
	if (!data->nb_eat)
		data->nb_eat = -1;
	ft_init_philo(data);
	if (ft_init_mutex(data))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 6)
	{
		data.nb_eat = ft_atoi(av[5]);
		if (data.nb_eat <= 0)
			return (1);
	}
	if (ac == 5 || ac == 6)
	{
		if ((ft_init_data(&data, av)) != 0)
			return (1);
		ft_philo(&data);
	}
	else
		ft_putstr("Wrong format: ./exe <philo> <death> <eat> <sleep> [meals]\n");
	return (0);
}

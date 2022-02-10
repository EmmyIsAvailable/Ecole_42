/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:57:18 by eruellan          #+#    #+#             */
/*   Updated: 2022/02/10 17:17:55 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_die(t_data *data, t_philo *philos)
{
	int	i;

	while (data->fed_up != 1 && data->death == 0)
	{
		i = 0;
		while (data->nb_eat != -1 && i < data->nb_philos
			&& philos[i].times_eaten >= data->nb_eat)
			i++;
		if (i == data->nb_philos)
			data->fed_up = 1;
		i = -1;
		while (++i < data->nb_philos && data->death == 0)
		{
			pthread_mutex_lock(&(data->meal_check));
			if (ft_timestamp() - philos[i].last_meal > data->time_death)
			{
				pthread_mutex_unlock(&(data->meal_check));
				ft_message(data, i, "died");
				data->death = 1;
			}
			pthread_mutex_unlock(&(data->meal_check));
		}
	}
}

void	ft_eat(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&(data->forks[philo->left_fork]));
	ft_message(data, philo->address, "has taken a fork");
	pthread_mutex_lock(&(data->forks[philo->right_fork]));
	ft_message(data, philo->address, "has taken a fork");
	ft_sleep(data->time_eat, data);
	pthread_mutex_unlock(&(data->forks[philo->right_fork]));
	pthread_mutex_unlock(&(data->forks[philo->left_fork]));
	ft_message(data, philo->address, "is eating");
	pthread_mutex_lock(&(data->meal_check));
	philo->last_meal = ft_timestamp();
	pthread_mutex_unlock(&(data->meal_check));
	(philo->times_eaten)++;
}

void	*ft_threads(void *philo_void)
{
	t_philo	*philo;

	philo = (t_philo *)philo_void;
	if (philo->address % 2 == 1)
		usleep(15000);
	while (philo->data->death == 0 && philo->data->fed_up != 1)
	{
		ft_eat(philo, philo->data);
		ft_message(philo->data, philo->address, "is sleeping");
		ft_sleep(philo->data->time_sleep, philo->data);
		ft_message(philo->data, philo->address, "is thinking");
	}
	return (NULL);
}

void	ft_exit_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
		pthread_mutex_destroy(&(data->forks[i]));
	pthread_mutex_destroy(&(data->is_writing));
	pthread_mutex_destroy(&(data->meal_check));
}

int	ft_philo(t_data *data)
{
	t_philo	*philos;
	int		i;

	i = 0;
	data->beginning = ft_timestamp();
	philos = data->philosophers;
	while (i < data->nb_philos)
	{
		pthread_mutex_lock(&(data->meal_check));
		philos[i].last_meal = ft_timestamp();
		pthread_mutex_unlock(&(data->meal_check));
		if (pthread_create(&(philos[i].thread_id),
				NULL, ft_threads, &(philos[i])) != 0)
			return (1);
		pthread_detach(philos[i].thread_id);
		usleep(500);
		i++;
	}
	ft_die(data, data->philosophers);
	ft_exit_mutex(data);
	return (0);
}

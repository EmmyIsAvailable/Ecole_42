/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:57:18 by eruellan          #+#    #+#             */
/*   Updated: 2022/02/15 16:21:48 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_die(t_data *data, t_philo *philos)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < data->nb_philos && !ft_is_alive(data))
		{
			pthread_mutex_lock(&(data->meal_check));
			if (ft_timestamp() - philos[i].last_meal > data->time_death)
			{
				ft_message(data, i, "died");
				pthread_mutex_lock(&data->check_death);
				data->death = 1;
				pthread_mutex_unlock(&data->check_death);
			}
			pthread_mutex_unlock(&(data->meal_check));
		}
		pthread_mutex_lock(&data->check_death);
		if (data->fed_up == 1)
			i = -5;
		pthread_mutex_unlock(&data->check_death);
		if (i == -5 || ft_export_die(data))
			break ;
	}
}

void	ft_eat(t_philo *philo, t_data *data)
{
	ft_message(data, philo->address, "is eating");
	ft_sleep(data->time_eat);
	pthread_mutex_lock(&(data->forks[philo->left_fork_id]));
	data->forks_bool[philo->left_fork_id] = 1;
	pthread_mutex_unlock(&(data->forks[philo->left_fork_id]));
	pthread_mutex_lock(&(data->forks[philo->right_fork_id]));
	data->forks_bool[philo->right_fork_id] = 1;
	pthread_mutex_unlock(&(data->forks[philo->right_fork_id]));
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
		ft_sleep(15);
	while (!ft_is_alive(philo->data) && (philo->data->nb_eat == -1
			|| philo->times_eaten < philo->data->nb_eat))
	{
		ft_get_forks(philo);
		ft_eat(philo, philo->data);
		ft_message(philo->data, philo->address, "is sleeping");
		ft_sleep(philo->data->time_sleep);
		ft_message(philo->data, philo->address, "is thinking");
		pthread_mutex_lock(&philo->data->check_death);
		if (philo->times_eaten == philo->data->nb_eat)
			philo->data->fed_up = 1;
		pthread_mutex_unlock(&philo->data->check_death);
	}
	return (NULL);
}

void	ft_exit_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
		pthread_join(data->philosophers[i].thread_id, NULL);
	pthread_mutex_destroy(&(data->is_writing));
	pthread_mutex_destroy(&(data->meal_check));
	pthread_mutex_destroy(&data->check_death);
	free(data->forks_bool);
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
		if (pthread_create(&(philos[i].thread_id),
				NULL, ft_threads, &(philos[i])) != 0)
			return (1);
		pthread_mutex_lock(&(data->meal_check));
		philos[i].last_meal = ft_timestamp();
		pthread_mutex_unlock(&(data->meal_check));
		i++;
	}
	ft_die(data, data->philosophers);
	ft_exit_mutex(data);
	return (0);
}

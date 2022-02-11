/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:03:17 by eruellan          #+#    #+#             */
/*   Updated: 2022/02/11 17:41:51 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_lock_forks(t_philo *philo)
{
	if (!philo->lfork)
	{
		pthread_mutex_lock(&philo->data->forks[philo->left_fork_id]);
		if (philo->data->forks_bool[philo->left_fork_id])
		{
			philo->data->forks_bool[philo->left_fork_id] = 0;
			(philo->forks)++;
			philo->lfork = 1;
			ft_message(philo->data, philo->address, "has taken a fork");
		}
		pthread_mutex_unlock(&philo->data->forks[philo->left_fork_id]);
	}
	if (!philo->rfork)
	{
		pthread_mutex_lock(&philo->data->forks[philo->right_fork_id]);
		if (philo->data->forks_bool[philo->right_fork_id])
		{
			philo->data->forks_bool[philo->right_fork_id] = 0;
			(philo->forks)++;
			philo->rfork = 1;
			ft_message(philo->data, philo->address, "has taken a fork");
		}
		pthread_mutex_unlock(&philo->data->forks[philo->right_fork_id]);
	}
}

void	ft_get_forks(t_philo *philo)
{
	while (!ft_is_alive(philo->data) && philo->forks != 2)
	{
		ft_lock_forks(philo);
		usleep(10);
	}
	philo->lfork = 0;
	philo->rfork = 0;
	philo->forks = 0;
	philo->data->forks_bool[philo->left_fork_id] = 1;
	philo->data->forks_bool[philo->right_fork_id] = 1;
}

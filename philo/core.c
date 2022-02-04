/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:43:06 by eruellan          #+#    #+#             */
/*   Updated: 2022/02/04 14:43:33 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philosopher *philo)
{

}

void	*ft_threads(t_philosopher *philo, t_data *data)
{
	if (philo->address % 2 == 0)
		usleep(15000);
	while (data->death == 0)
	{
		ft_eat(philo);

	}
}

int	ft_philo(t_data *data)
{
	int	*philos;
	int	i;

	i = 0;
	data->beginning = ft_timestamp();
	data->philosophers = philos;
	while (i < data->nb_philos)
	{
		if (pthread_create(&(philos[i].adress), NULL, ft_threads, (&philos[i], &data)) != 0)
			return (1);
		i++;
	}	
}

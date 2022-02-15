/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:49:33 by eruellan          #+#    #+#             */
/*   Updated: 2022/02/15 15:44:39 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	signe;
	int	i;

	i = 0;
	res = 0;
	signe = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * signe);
}

long long	ft_timestamp(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	ft_is_alive(t_data *data)
{
	int	alive;

	pthread_mutex_lock(&data->check_death);
	alive = data->death;
	pthread_mutex_unlock(&data->check_death);
	return (alive);
}

void	ft_message(t_data *data, int address, char *str)
{
	pthread_mutex_lock(&(data->is_writing));
	if (!ft_is_alive(data))
	{
		printf("%lld: %d %s\n",
			(ft_timestamp() - data->beginning), (address + 1), str);
	}
	pthread_mutex_unlock(&data->is_writing);
	return ;
}

void	ft_sleep(int time)
{
	long long	start;

	start = ft_timestamp();
	while (1)
	{
		if (ft_timestamp() - start >= time)
			break ;
		usleep(50);
	}
}

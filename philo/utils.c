/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:49:33 by eruellan          #+#    #+#             */
/*   Updated: 2021/11/23 10:50:38 by eruellan         ###   ########.fr       */
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

	gettimeoftheday(&t, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_message(t_data *data, int address, char *str)
{
	pthread_mutex_lock(&(data->writing));
	if (!data->death)
		printf("%lld : Philosopher %d %s\n", (ft_timestamp() - data->beginning), (address + 1), str);
	pthread_mutex_unlock(&data->writing);
	return ;
}

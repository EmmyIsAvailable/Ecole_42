/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:43:38 by eruellan          #+#    #+#             */
/*   Updated: 2022/02/04 14:43:40 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>

struct s_data;

typedef struct s_philo
{
	pthread_t	address;
}	t_philo;

typedef struct s_data
{
	int		nb_philos;
	int		time_death;
	int		time_eat;
	int		time_sleep;
	int		nb_eat;
	long long	beginning;
	bool		death;
	pthread_mutex_t	forks[250];
	t_philo		philosophers[250];
	pthread_mutex_t	is_writing;
}	t_data;

/*main*/
void	ft_putstr(char *str);
int		ft_init_philo(t_data *data);
int		ft_init_data(t_data *datam char **av);

/*utils*/
int		ft_atoi(const char *str);
long long	ft_timestamp(void);
void		ft_message(t_data *data, int address, char *str);

/*core*/
int		ft_philo(t_data *data);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:03:50 by eruellan          #+#    #+#             */
/*   Updated: 2022/02/15 16:21:32 by eruellan         ###   ########.fr       */
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

struct	s_data;

typedef struct s_philo
{
	int				address;
	int				forks;
	int				left_fork_id;
	int				right_fork_id;
	int				lfork;
	int				rfork;
	long long		last_meal;
	int				times_eaten;
	pthread_t		thread_id;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int					nb_philos;
	int					time_death;
	int					time_eat;
	int					time_sleep;
	int					nb_eat;
	long long			beginning;
	int					death;
	int					fed_up;
	char				*forks_bool;
	pthread_mutex_t		forks[250];
	t_philo				philosophers[250];
	pthread_mutex_t		is_writing;
	pthread_mutex_t		check_death;
	pthread_mutex_t		meal_check;
}	t_data;

/*main*/
void			ft_putstr(char *str);
int				ft_init_philo(t_data *data);
int				ft_init_data(t_data *data, char **av);
int				ft_init_mutex(t_data *data);

/*utils*/
int				ft_atoi(const char *str);
long long		ft_timestamp(void);
void			ft_message(t_data *data, int address, char *str);
void			ft_sleep(int time);
int				ft_is_alive(t_data *data);

/*core*/
int				ft_philo(t_data *data);
void			ft_eat(t_philo *philo, t_data *data);
void			ft_die(t_data *data, t_philo *philos);
void			ft_exit_mutex(t_data *data);
void			*ft_threads(void *philo);

/*forks*/
void			ft_get_forks(t_philo *philo);
void			ft_lock_forks(t_philo *philo);
int				ft_export_die(t_data *data);

#endif

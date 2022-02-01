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

}	t_philo;

typedef struct s_data
{
	int		nb_philos;
	int		time_death;
	int		time_eat;
	int		time_sleep;
	int		nb_eat;
	pthread_mutex_t	forks[250];
	t_philo		philosophers[250];
	pthread_mutex_t	is_writing;
}	t_data;

/*main*/
void	ft_putstr(char *str);

/*utils*/
int		ft_atoi(const char *str);
long long	ft_timestamp(void);

#endif

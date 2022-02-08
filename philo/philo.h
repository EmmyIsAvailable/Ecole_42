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
	int		address;
	int		left_fork;
	int		right_fork;
	long long	last_meal;
	int		times_eaten;
	pthread_t	thread_id;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int		nb_philos;
	int		time_death;
	int		time_eat;
	int		time_sleep;
	int		nb_eat;
	long long	beginning;
	int		death;
	int		fed_up;
	pthread_mutex_t	forks[250];
	t_philo		philosophers[250];
	pthread_mutex_t	is_writing;
	pthread_mutex_t	busy_checking;
}	t_data;

/*main*/
void	ft_putstr(char *str);
int		ft_init_philo(t_data *data);
int		ft_init_data(t_data *data, char **av);
int		ft_init_mutex(t_data *data);

/*utils*/
int		ft_atoi(const char *str);
long long	ft_timestamp(void);
void		ft_message(t_data *data, int address, char *str);
void		ft_sleep(int time, t_data *data);

/*core*/
int		ft_philo(t_data *data);
void		ft_eat(t_philo *philo, t_data *data);
void		ft_die(t_data *data);
void		ft_exit_mutex(t_data *data);
void		*ft_threads(void *philo);

#endif

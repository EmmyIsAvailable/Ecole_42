#include "philo.h"

void	ft_putstr(char *str)
{
	int	i;

	while (str[i])
		i++;
	write(1, str, i);
}

int	ft_init_philo(t_data *data)
{
	int	i;

	i = data->nb_philos;
	while (i >= 0)
	{
		data->philosophers[i].address = i;
		i--;
	}
}

int	ft_init_data(t_data *data, char **av)
{
	data->nb_philos = ft_atoi(av[1]);
	data->time_death = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	data->death = 0;
	if (data->nb_philos < 1 || data->nb_philos > 250 || data->time_death < 0 || data->time_eat < 0 || data->time_sleep < 0)
		return (1);
	if (!data->nb_eat)
		data->nb_eat = -1;
	ft_init_philo(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 6)
	{
		data.nb_eat = ft_atoi(av[5]);
		if (data.nb_eat <= 0)
			return (1);
	}
	if (ac == 5 || ac == 6)
	{
		ft_init_data(&data, av);
		ft_philo(&data);
	}
	else
		ft_putstr("Wrong format : ./philo <nb_philo> <time_death> <time_eat> <time_sleep> [nb_eat]\n");
	return (0);
}

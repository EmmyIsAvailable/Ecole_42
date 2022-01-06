#include "push_swap.h"

void	check_doubles(t_var *arg)
{
	int	i;
	int	j;

	i = -1;
	while (arg->tab[++i])
	{
		j = i + 1;
		while (arg->tab[j++])
		{
			if (ft_strcmp(arg->tab[i], arg->tab[j]) == 0)
			{
				//free tab
				ft_error("Error : double values\n", 1);
			}
		}
	}
}

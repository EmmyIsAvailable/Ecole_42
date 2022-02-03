/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:21:23 by eruellan          #+#    #+#             */
/*   Updated: 2022/01/31 13:55:34 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	**ft_free_tab(char **data)
{
	int	i;

	i = -1;
	while (data[++i])
	{
		free(data[i]);
		data[i] = NULL;
	}
	free(data);
	return (NULL);
}

long long	ft_atoll(char *nb)
{
	unsigned long long	res;
	int					signe;
	int					i;

	i = 0;
	signe = 1;
	res = 0;
	while (nb[i] == '\f' || nb[i] == '\n' || nb[i] == '\r' || nb[i] == '\t'
		|| nb[i] == '\v' || nb[i] == ' ')
		i++;
	if (nb[i] == '-')
		signe = -1;
	if (nb[i] == '-' || nb[i] == '+')
		i++;
	while (nb[i] >= '0' && nb[i] <= '9')
	{
		res = res * 10 + nb[i] - '0';
		i++;
	}
	return (res * signe);
}

int	ft_is_in_scope(char c)
{
	if (c >= 32 && c <= 42)
		return (0);
	if (c == 44)
		return (0);
	if (c >= 46 && c <= 47)
		return (0);
	if (c >= 58 && c <= 126)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:00:11 by eruellan          #+#    #+#             */
/*   Updated: 2022/01/18 13:58:55 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_point_bresenham(t_mlx *var)
{
	if (var->point.x2 > var->point.x1)
		var->point.stepx = 1;
	else
		var->point.stepx = -1;
	if (var->point.y2 > var->point.y1)
		var->point.stepy = 1;
	else
		var->point.stepy = -1;
	if (var->point.dx > var->point.dy)
		var->point.e = var->point.dx / 2;
	else
		var->point.e = -var->point.dy / 2;
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_creation(av[1]);
	else
		perror("Wrong format");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:20:45 by eruellan          #+#    #+#             */
/*   Updated: 2022/01/10 16:23:55 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	col_pt_begin(t_mlx *var)
{
	var->point.x1 = var->point.x;
	var->point.y1 = var->point.y;
}

void	col_pt_next(t_mlx *var)
{
	var->point.x2 = var->point.x;
	var->point.y2 = var->point.y + var->point.space;
}

void	li_pt_next(t_mlx *var)
{
	var->point.x2 = var->point.x + var->point.space;
	var->point.y2 = var->point.y;
}

void	ft_bresenham(t_mlx *var)
{
	var->point.dx = (abs(var->point.x2 - var->point.x1));
	var->point.stepx = (var->point.x2 > var->point.x1 ? 1 : -1);
	var->point.dy = (abs(var->point.y2 - var->point.y1));
	var->point.stepy = (var->point.y2 > var->point.y1 ? 1 : -1);
	var->point.e = (var->point.dx > var->point.dy ? var->point.dx : -var->point.dy) / (2);
	while (1)
	{
		my_pixel_put(var, var->point.x1, var->point.y1);
		if (var->point.x1 == var->point.x2 && var->point.y1 == var->point.y2)
			break ;
		if (var->point.dx > -var->point.e)
		{
			var->point.e -= var->point.dy;
			var->point.x1 += var->point.stepx;
		}
		if (var->point.dy > var->point.e)
		{
			var->point.e += var->point.dx;
			var->point.y1 += var->point.stepy;
		}
	}
}

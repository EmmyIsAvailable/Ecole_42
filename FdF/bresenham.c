/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:20:45 by eruellan          #+#    #+#             */
/*   Updated: 2022/01/17 16:55:07 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
void	col_pt_begin(t_mlx *var)
{
	var->point.x1 = var->point.x - var->point.y;
	var->point.y1 = var->point.x + var->point.y - var->point.alt * var->map.map[var->map.y][var->map.x];
}

void	li_pt_begin(t_mlx *var)
{
	var->point.x1 = var->point.x - var->point.y;
	var->point.y1 = var->point.x + var->point.y - var->point.alt * var->map.map[var->map.y][var->map.x];
}

void	col_pt_next(t_mlx *var)
{
	var->point.x2 = var->point.x - var->point.y - var->point.space;
	var->point.y2 = - var->point.alt * var->map.map[var->map.y + 1][var->map.x] + var->point.space + var->point.y + var->point.x;
}

void	li_pt_next(t_mlx *var)
{
	var->point.x2 = var->point.x + var->point.space - var->point.y;
	var->point.y2 = var->point.y + var->point.space - var->point.alt * var->map.map[var->map.y][var->map.x + 1] + var->point.x;
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
		ft_colors(var);
		my_pixel_put(var, var->point.x1 + var->point.left_right, var->point.y1 + var->point.up_down);
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

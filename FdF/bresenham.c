/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:20:45 by eruellan          #+#    #+#             */
/*   Updated: 2021/12/21 16:21:10 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

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
	while (1)
	{
		my_pixel_put(var, var->point.x1, var->point.y1);
		if (var->point.x1 == var->point.x2 && var->point.y1 == var->point.y2)
			break ;
		var->point.y1++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:23:55 by eruellan          #+#    #+#             */
/*   Updated: 2021/12/21 16:21:52 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	ft_draw_one_col(t_mlx *var)
{
	while (var->point.y < ((var->map.li - 1) * var->point.space))
	{
		col_pt_next(var);
		ft_bresenham(var);	
		var->map.y++;
		var->point.y += var->point.space;
		var->point.x1 = var->point.x2;
		var->point.y1 = var->point.y2;
	}
}

void	ft_draw_col(t_mlx *var)
{
	var->map.x = 0;
	var->point.x = 0;
	while (var->point.x < (var->map.col * var->point.space))
	{
		var->point.y = 0;
		var->map.y = 0;
		col_pt_begin(var);
		ft_draw_one_col(var);
		var->map.x++;
		var->point.x += var->point.space;
	}
}

void	ft_draw_one_li(t_mlx *var)
{
	while (var->point.x < (var->map.col * var->point.space))
	{
		li_pt_next(var);
		ft_bresenham(var);
		var->map.x++;
		var->point.x += var->point.space;
		var->point.x1 = var->point.x2;
		var->point.y1 = var->point.y2;
	}
}

void	ft_draw_li(t_mlx *var)
{
	
}

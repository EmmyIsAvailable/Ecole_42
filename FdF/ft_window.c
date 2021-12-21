/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:05:25 by eruellan          #+#    #+#             */
/*   Updated: 2021/12/21 13:55:48 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	close_win(t_mlx *var)
{
	mlx_destroy_window(var->mlx, var->win);
	exit (0);
}

void	my_pixel_put(t_mlx *var, int x, int y)
{
	if (x > 0 && x < var->win_len && y > 0 && y < var->win_width)
	{
		var->img.addr[(y * var->img.size_l) + (x * (var->img.bpp / 8))] = var->color.red;
		var->img.addr[(y * var->img.size_l) + (x * (var->img.bpp / 8)) + 1] = var->color.green;
		var->img.addr[(y * var->img.size_l) + (x * (var->img.bpp / 8)) + 2] = var->color.blue;
	}
}

void	ft_aff_map(t_mlx *var)
{
	ft_draw_col(var);
}

void	ft_aff_window(t_mlx *var)
{
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, var->win_len, var->win_width, "fdf");
	var->img.img = mlx_new_image(var->mlx, var->win_len, var->win_width);

	var->img.addr = mlx_get_data_addr(var->img.img, &var->img.bpp, &var->img.size_l, &var->img.endian);

	ft_aff_map(var);

	mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);

	mlx_hook(var->win, 2, 27, close_win, var); 
	mlx_hook(var->win, 17, 0L, close_win, var);
	
	mlx_loop(var->mlx);
}

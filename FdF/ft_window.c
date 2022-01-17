/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:05:25 by eruellan          #+#    #+#             */
/*   Updated: 2022/01/17 13:12:03 by eruellan         ###   ########.fr       */
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

int	ft_expose_hook(t_mlx *var)
{
	var->img.img = mlx_new_image(var->mlx, var->win_len, var->win_width);
	var->img.addr = mlx_get_data_addr(var->img.img, &var->img.bpp, &var->img.size_l, &var->img.endian);
	ft_draw_col(var);
	ft_draw_li(var);
	mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);
	mlx_destroy_image(var->mlx, var->img.img);
	return (0);
}

int	ft_key_hook(int keycode, t_mlx *var)
{
	if (keycode == ESC)
		close_win(var);
	else if (keycode == R)
		var->color.red -= 20;
	else if (keycode == G)
		var->color.green -= 20;
	else if (keycode == B)
		var->color.blue -= 20;
	else if (keycode == NUMPAD_PLUS || keycode == NUMPAD_MINUS)
		ft_zoom(keycode, var);
	else if (keycode == UP || keycode == DOWN || keycode == RIGHT || keycode == LEFT)
		ft_move(keycode, var);
	else if (keycode == PLUS || keycode == MINUS)
		ft_altitude(keycode, var);
	ft_expose_hook(var);
	return (0);
}

void	ft_aff_window(t_mlx *var)
{
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, var->win_len, var->win_width, "fdf");
	mlx_key_hook(var->win, ft_key_hook, var);
	mlx_expose_hook(var->win, ft_expose_hook, var);
	mlx_loop(var->mlx);
}

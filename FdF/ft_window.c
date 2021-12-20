/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:05:25 by eruellan          #+#    #+#             */
/*   Updated: 2021/12/20 17:04:02 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	close_win(t_mlx *var)
{
	mlx_destroy_window(var->mlx, var->win);
	exit (0);
}

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_l + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	ft_aff_map(t_mlx *var)
{
	var->map.y = 0;
	//printf("%d, %d", var->map.li, var->map.col);
	while (var->map.map[var->map.y][var->map.x])
	{
		
		var->map.x = 0;
		while (var->map.map[var->map.y][var->map.x])
		{
			my_pixel_put(&var->img, var->map.x, var->map.y, 0x0FF0000);
			mlx_pixel_put(var->mlx, var->win, var->map.x, var->map.y, 0x00FF0000);
			var->map.x++;
		}
		var->map.y++;
	}
}

void	ft_aff_window(t_mlx *var)
{
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, 1920, 1080, "fdf");
	var->img.img = mlx_new_image(var->mlx, 1920, 1080);

	var->img.addr = mlx_get_data_addr(var->img.img, &var->img.bpp, &var->img.size_l, &var->img.endian);

	ft_aff_map(var);

	mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);

	mlx_hook(var->win, 2, 27, close_win, var); 
	mlx_hook(var->win, 17, 0L, close_win, var);
	
	mlx_loop(var->mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:05:25 by eruellan          #+#    #+#             */
/*   Updated: 2021/12/20 12:12:04 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	ft_parsing(int fd, t_mlx var)
{
	char 	*line;
	char	**split_line;

	while ((line = get_next_line(fd)) != NULL)
	{
		var.map.x = 0;
		split_line = ft_split(line, ' ');
		while (split_line[var.map.x] != NULL)
		{
			var.map.map[var.map.y][var.map.x] =
				ft_atoi(split_line[var.map.x]);
			free(split_line[var.map.x]);
			var.map.x++;
		}
		free(split_line);
		free(line);
		var.map.y++;
	}
}

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

void	ft_aff_window(int fd)
{
	t_mlx	var;

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 1920, 1080, "fdf");
	var.img.img = mlx_new_image(var.mlx, 1920, 1080);

	var.img.addr = mlx_get_data_addr(var.img.img, &var.img.bpp, &var.img.size_l, &var.img.endian);
	
	ft_parsing(fd, var);
	
	mlx_put_image_to_window(var.mlx, var.win, var.img.img, 0, 0);

	mlx_hook(var.win, 2, 27, close_win, &var); 
	mlx_hook(var.win, 17, 0L, close_win, &var);
	
	mlx_loop(var.mlx);
}

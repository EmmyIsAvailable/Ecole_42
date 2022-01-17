/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:33:03 by eruellan          #+#    #+#             */
/*   Updated: 2022/01/17 16:54:58 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_nb_col_li(char *av, t_mlx *var)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = (open(av, O_RDONLY));
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	while (line[i])
	{
		if (line[i] == ' ')
			var->map.col++;
		i++;
	}
	if (line)
	{
		var->map.li++;
		free(line);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		var->map.li++;
		free(line);
	}
	close (fd);
	return (0);
}

int	**ft_newtab(int x, int y)
{
	int	i;
	int	**tab;
	int	*ligne;

	i = 0;
	tab = (int **)malloc(sizeof(tab) * y);
	if (!tab)
		return (NULL);
	ligne = (int *)malloc(sizeof(ligne) * (x * y));
	if (!ligne)
		return (NULL);
	while (i < y)
	{
		tab[i] = &ligne[i * x];
		i++;
	}
	return (tab);
}

int	ft_parsing(int fd, t_mlx *var)
{
	char 	*line;
	char	**split_line;

	if (!(var->map.map = ft_newtab(var->map.col, var->map.li)))
		return (-1);
	while ((line = get_next_line(fd)) != NULL)
	{
		var->map.x = 0;
		split_line = ft_split(line, ' ');
		while (split_line[var->map.x] != NULL)
		{
			var->map.map[var->map.y][var->map.x] =
				ft_atoi(split_line[var->map.x]);
			free(split_line[var->map.x]);
			var->map.x++;
		}
		free(split_line);
		free(line);
		var->map.y++;
	}
	return (0);
}

void	ft_colors(t_mlx *var)
{
	if (var->map.map[var->map.y][var->map.x] < 0)
	{
		var->color.red = 0;
		var->color.green = 0 - 4 * var->map.map[var->map.y][var->map.x];
		var->color.blue = 255 + 4 * var->map.map[var->map.y][var->map.x];
	}
	else if (var->map.map[var->map.y][var->map.x] < 10)
	{
		var->color.red = 160 + var->map.map[var->map.y][var->map.x] * 9;
		var->color.green = 0 + 3 * var->map.map[var->map.y][var->map.x];
		var->color.blue = 180 - var->map.map[var->map.y][var->map.x] * 10;
	}
	if (var->map.map[var->map.y][var->map.x] < 20)
	{
		var->color.red = 60 + var->map.map[var->map.y][var->map.x] * 9;
		var->color.green = 85 + var->map.map[var->map.y][var->map.x] * 8;
		var->color.blue = 7 * var->map.map[var->map.y][var->map.x];
	}	
	else
	{
		var->color.red = 255 - var->map.map[var->map.y][var->map.x];
		var->color.green = 0 + var->map.map[var->map.y][var->map.x];
		var->color.blue = 0;
	}
}

int	ft_creation(char *av)
{
	t_mlx	var;
	int		fd;

	ft_bzero(&var, sizeof(t_mlx));
	ft_nb_col_li(av, &var);
	fd = (open(av, O_RDONLY));
	if (fd == -1)
		return (-1);
	ft_parsing(fd, &var);
	ft_size_win(&var);
	ft_inbetween(&var);
	var.point.alt = var.point.space;
	var.point.left_right = var.win_len / 4;
	var.point.up_down = var.win_width / 4;
	ft_aff_window(&var);
	close(fd);
	ft_bzero(&var, sizeof(t_mlx));
	return (0);
}

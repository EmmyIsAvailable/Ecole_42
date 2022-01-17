/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:33:03 by eruellan          #+#    #+#             */
/*   Updated: 2022/01/17 13:11:07 by eruellan         ###   ########.fr       */
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
	var.color.red = 255;
	var.color.green = 255;
	var.color.blue = 255;
	var.point.alt = -5;
	var.point.left_right = var.win_len / 4;
	var.point.up_down = var.win_width / 4;
	ft_aff_window(&var);
	close(fd);
	ft_bzero(&var, sizeof(t_mlx));
	return (0);
}

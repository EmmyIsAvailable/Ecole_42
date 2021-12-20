/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 09:50:18 by eruellan          #+#    #+#             */
/*   Updated: 2021/12/20 16:12:50 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./miniLibX/mlx.h"
# include "./libft/libft.h"

# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <math.h>
# include <unistd.h>

typedef struct s_map
{
	int	**map;
	int	x;
	int y;
	int	col;
	int	li;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_map	map;
}	t_mlx;

void	ft_aff_window(t_mlx *var);
int		ft_parsing(int fd, t_mlx *var);
int		ft_creation(char *av);

#endif

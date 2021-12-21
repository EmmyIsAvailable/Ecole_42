/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 09:50:18 by eruellan          #+#    #+#             */
/*   Updated: 2021/12/21 16:29:54 by eruellan         ###   ########.fr       */
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

typedef struct s_color
{
	int	color;
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_point
{
	int	x;
	int	y;
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int	pos;
	int	space;

}	t_point;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		win_len;
	int		win_width;
	t_img	img;
	t_map	map;
	t_color	color;
	t_point	point;
}	t_mlx;

void	ft_aff_window(t_mlx *var);
int		ft_parsing(int fd, t_mlx *var);
int		ft_creation(char *av);
void	ft_size_win(t_mlx *var);
void	ft_inbetween(t_mlx *var);
void	ft_draw_col(t_mlx *var);
void	my_pixel_put(t_mlx *var, int x, int y);
void	col_pt_begin(t_mlx *var);
void	col_pt_next(t_mlx *var);
void	ft_draw_li(t_mlx *var);
void	li_pt_next(t_mlx *var);
void	ft_bresenham(t_mlx *var);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_details.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:14:24 by eruellan          #+#    #+#             */
/*   Updated: 2022/01/17 16:54:30 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom(int keycode, t_mlx *var)
{
	if (keycode == NUMPAD_PLUS)
		var->point.space += 5;
	else if (keycode == NUMPAD_MINUS)
		if (var->point.space > 5)
			var->point.space -= 5;
}

void	ft_move(int keycode, t_mlx *var)
{
	if (keycode == UP)
		var->point.up_down -= 40;
	else if (keycode == DOWN)
		var->point.up_down += 40;
	else if (keycode == LEFT)
		var->point.left_right -= 40;
	else if (keycode == RIGHT)
		var->point.left_right += 40;
}

void	ft_altitude(int keycode, t_mlx *var)
{
	if (keycode == PLUS)
		var->point.alt += 5;
	else if (keycode == MINUS)
		var->point.alt -= 5;
}

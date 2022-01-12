/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:48:09 by eruellan          #+#    #+#             */
/*   Updated: 2022/01/11 15:18:39 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	ft_size_win(t_mlx *var)
{
	if (var->map.col <= 10)
		var->win_len = var->map.col * 100;
	else if (var->map.col <= 20)
		var->win_len = var->map.col * 70;
	else if (var->map.col <= 50)
		var->win_len = var->map.col * 40;
	else
		var->win_len = var->map.col * 10;
	if (var->map.li <= 20)
		var->win_width = var->map.li * 100;
	else if (var->map.li <= 50)
		var->win_width = var->map.li * 40;
	else
		var->win_width = var->map.li * 10;
}

void	ft_inbetween(t_mlx *var)
{
	if (var->map.col <= 20)
		var->point.space = 25;
	else if (var->map.col <= 50)
		var->point.space = 20;
	else if (var->map.col <= 100)
		var->point.space = 10;
	else
		var->point.space = 2;
}

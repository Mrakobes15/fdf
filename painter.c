/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:11:37 by risolon           #+#    #+#             */
/*   Updated: 2022/04/09 17:38:09 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_abs(float num)
{
	if (num >= 0)
		return (num);
	else
		return (-num);
}

float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	draw_line(t_dot a, t_dot b, t_fdf *data)
{
	float	x_step;
	float	y_step;
	float	max;

	x_step = b.x - a.x;
	y_step = b.y - a.y;
	max = ft_max(ft_abs(x_step), ft_abs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, a.x, b.x, a.color);
		a.x += x_step;
		a.y += y_step;
	}
}
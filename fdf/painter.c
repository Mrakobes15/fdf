/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:11:37 by risolon           #+#    #+#             */
/*   Updated: 2022/04/29 14:41:54 by risolon          ###   ########.fr       */
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

void	isometric(t_dot *dot, t_fdf *data)
{
	dot->x = (dot->x - dot->y) * cos(data->angle);
	dot->y = (dot->x + dot->y) * sin(data->angle) - dot->z;
}

void	draw_line(t_dot a, t_dot b, t_fdf *data)
{
	float	x_step;
	float	y_step;
	float	max;
	int		color;

	ft_setter(&a, &b, data);
	x_step = b.x - a.x;
	y_step = b.y - a.y;
	color = set_color(a, b);
	max = ft_max(ft_abs(x_step), ft_abs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, a.x, a.y, color);
		a.x += x_step;
		a.y += y_step;
	}
}

void	ft_painter(t_dot **matrix, t_fdf *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (1)
		{
			if (matrix[y + 1])
				draw_line(matrix[y][x], matrix[y + 1][x], data);
			if (!matrix[y][x].last)
				draw_line(matrix[y][x], matrix[y][x + 1], data);
			if (matrix[y][x].last)
				break ;
			x++;
		}
		y++;
	}	
}

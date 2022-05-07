/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 18:42:33 by risolon           #+#    #+#             */
/*   Updated: 2022/05/07 19:41:27 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_key(int key)
{
	return (key == 123 || key == 124 || key == 125 || \
	key == 126 || key == 27 || key == 24 || key == 256 || \
	key == 269 || key == 34);
}

void	key_hook(int key, t_fdf *data)
{
	if (key == 125)
		data->y_shift += data->zoom;
	if (key == 126)
		data->y_shift -= data->zoom;
	if (key == 124)
		data->x_shift += data->zoom;
	if (key == 123)
		data->x_shift -= data->zoom;
	if (key == 27)
	{
		if (data->zoom > 1)
			data->zoom -= 3;
		data->z_zoom = data->zoom / 6;
	}
	if (key == 24)
	{
		data->zoom += 3;
		data->z_zoom = data->zoom / 6;
	}
	if (key == 256)
		data->angle += 0.1;
	if (key == 269)
		data->angle -= 0.1;
	if (key == 34)
		data->isometric *= -1;
}

int	deal_keyboard(int key, t_fdf *data)
{
	if (is_key(key))
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		key_hook(key, data);
		ft_painter(data->matrix, data);
	}
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		clear(data->matrix, data);
		// free(data->matrix);
		exit (0);
	}
	return (0);
}

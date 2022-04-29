/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:40:19 by risolon           #+#    #+#             */
/*   Updated: 2022/04/25 15:14:08 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_size(int key, t_fdf *data)
{
	if ((key == 1 && data->y_width <= 500)
		|| (key == 0 && data->x_width <= 500))
		return (1);
	if ((key == 13 && data->y_width > 1350)
		|| (key == 2 && data->x_width > 2550))
		return (1);
	return (0);
}

void	change_size(int key, t_fdf *data)
{
	if (check_size(key, data))
		return ;
	if (key == 0)
		data->x_width -= 100;
	if (key == 2)
		data->x_width += 100;
	if (key == 1)
		data->y_width -= 100;
	if (key == 13)
		data->y_width += 100;
}

void	window_size(int key, t_fdf *data)
{
	change_size(key, data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->x_width,
			data->y_width, "FDF");
	data->x_shift = data->x_width / 3;
	data->y_shift = data->y_width / 3;
	ft_painter(data->matrix, data);
	mlx_key_hook(data->win_ptr, deal_keyboard, data->matrix);
	mlx_loop(data->mlx_ptr);
}
